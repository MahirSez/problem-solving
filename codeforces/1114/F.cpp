#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("dull.in","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	400005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , q , mark[MAX] , ara[MAX];
vector<int>prm;

ll tree1[4*MAX] , lazy1[4*MAX];
ll tree2[4*MAX] , lazy2[4*MAX];

void seive() {

    for(int i = 2 ; i * i <= 300 ; i++) {

        if( mark[i] ) continue;
        for(int j =  i * i ; j<= 300 ; j+=i ) {
			mark[j] = 1;
        }
    }
    for(int i = 2 ; i <= 300 ; i++) {
		if( mark[i] == 0) prm.push_back(i);
    }
}


void push1(int node , int l , int r ) {

    if( lazy1[node] )  {

        tree1[node] |= lazy1[node];

        if( l != r ) {

            lazy1[node<<1] |= lazy1[node];
            lazy1[node<<1|1] |= lazy1[node];
        }
        lazy1[node] = 0;
    }
}

void build1(int node , int l , int r) {

	if( l == r) {
		ll mask = 0;
		ll tmp = ara[r];

        for(int i =0 ; i < prm.size() ; i++ ) {

            if( tmp%prm[i] == 0 ) {
                while( tmp%prm[i] ==0 ) tmp/=prm[i];
                mask |=(1LL<<i);
            }
        }
        assert(tmp == 1);
        tree1[node] = mask;
        return ;
	}
	int mid = (l+r)>>1;
	build1(node<<1 , l , mid);
	build1(node<<1|1 , mid+1 , r);
	tree1[node] = tree1[node<<1] | tree1[node<<1|1];
}


void build2(int node , int  l , int r) {

	if( l == r) {

        tree2[node] = ara[l];
        return;
	}

	int mid = (l+r)>>1;
    build2(node<<1 , l , mid);
    build2(node<<1|1 , mid+1 , r);
    tree2[node] = (tree2[node<<1] * tree2[node<<1|1] )%MOD ;
}

void update1(int node , int l , int r , int frm , int to , ll val) {

	push1(node , l , r);
    if( l>r || l > to || r < frm ) return;

    if( l >=frm && r <= to) {
        lazy1[node] |= val;
        push1(node , l , r);
        return;
    }

    int mid = (l+r)>>1;
    update1(node<<1 , l , mid , frm , to , val);
    update1(node<<1|1 , mid+1 , r , frm , to , val);

    tree1[node] = tree1[node<<1] | tree1[node<<1|1];
}
ll bigMod(ll a , ll b) {

    ll p ;
    if( b == 0) return 1;
    p = ( bigMod(a , b/2) % MOD );
    p = ( p * p) % MOD;
    if( b & 1 ) p = ( p * a) % MOD;
    return p;
}


void push2(int node , int l , int r) {

	if(lazy2[node] > 1) {


        ll tmp = bigMod(lazy2[node] , r-l+1);

//        cout<<"     "<<lazy2[node]<<" "<<r<<" "<<l<<" "<<tmp<<endl;

		tree2[node] = (tree2[node] * tmp) %MOD;

		if( l != r) {

            lazy2[node<<1] *= lazy2[node];
            lazy2[node<<1|1] *= lazy2[node];

            lazy2[node<<1] %= MOD;
            lazy2[node<<1|1] %= MOD;
		}
		lazy2[node] = 1;

	}
}


void update2(int node , int l , int r , int frm  , int to , ll val) {


//	cout<<" --- "<<val<<endl;
	push2(node , l , r);

    if( l > r || l > to || r < frm ) return;

    if( l>= frm && r <= to) {
        lazy2[node] *=val;
//        cout<<"? "<<lazy2[node]<<endl;
        lazy2[node]%=MOD;
        push2(node , l , r);
        return ;
    }

    int mid = (l+r)>>1;
    update2(node<<1 , l , mid , frm , to , val);
    update2(node<<1|1 , mid+1 , r , frm , to , val);

    tree2[node] = (tree2[node<<1] * tree2[node<<1|1] )%MOD ;
}



ll query1(int node , int l , int r , int frm , int to ) {
	push1(node , l , r);
	if( l > r || l > to || r < frm) return 0;

	if( l>= frm && r<=to) {
//		cout<<node<<" "<<l<<" "<<r<<" "<<tree1[node]<<endl;
		return tree1[node];
	}

	int mid = (l+r)>>1;
	ll q1 = query1(node<<1  , l , mid , frm , to);
	ll q2 = query1(node<<1|1 , mid+1 , r , frm , to);
	return (q1|q2);
}

ll query2(int node , int l , int r , int frm , int to ) {
	push2(node , l , r);
	if( l > r || l > to || r < frm) return 1LL;

	if( l>= frm && r<=to) {
//		cout<<node<<" "<<l<<" "<<r<<" "<<tree1[node]<<endl;
		return tree2[node]%MOD;
	}

	int mid = (l+r)>>1;
	ll q1 = query2(node<<1  , l , mid , frm , to);
	ll q2 = query2(node<<1|1 , mid+1 , r , frm , to);
	return (q1*q2)%MOD;
}

ll modInverse( ll x ) {
    return bigMod(x, MOD-2);
}
ll modIn[400];

void pre() {

    for(int i = 0 ; i < prm.size() ; i++ ) {

        modIn[prm[i]] = modInverse(prm[i]);
    }
}

ll get(ll prod , ll mask) {


	ll ans = prod;


    for(int  i =0 ; i < 63 ; i++) {
		if( mask & (1LL<<i) ) {
			ans = (ans * (prm[i] - 1) )%MOD;
			ans = (ans * modIn[prm[i]] ) %MOD;
		}
    }

    return ans;
}


void print() {


	for(int i =1 ;i <= 7 ; i++) {
		cout<<tree2[i]<<" ";
	}
	cout<<endl;
}

int main()
{

    fastRead;
	seive();
	pre();
	for(int  i =1 ; i < 4*MAX ; i++) lazy2[i] = 1;

    cin>>n>>q;
    for(int i = 1 ; i<= n ; i++ ) {
		cin>>ara[i];
    }
    build1(1 , 1 , n);
    build2(1 , 1 , n);

//    print();

    while( q-- ) {

        string str ;
        int frm , to;
        cin>>str>>frm>>to;

        if( str == "TOTIENT") {
			ll mask = query1(1 , 1 , n , frm , to) ;
			ll prod = query2(1 , 1 , n , frm , to) ;


            cout<<get(prod , mask)<<'\n';
        }
        else {
			int val ;
			cin>>val;

			update2(1 , 1 , n , frm , to , val);

            ll mask = 0;

            for(int i =0 ; i < prm.size() ; i++ ) {

				if( val%prm[i] == 0 ) {
					while( val%prm[i] ==0 ) val/=prm[i];
					mask |=(1LL<<i);
				}
			}

			update1(1 , 1 , n , frm , to , mask);

        }
    }

    return 0;
}


/*

4 4
5 9 1 2
MULTIPLY 2 4 5
TOTIENT 2 4
*/
