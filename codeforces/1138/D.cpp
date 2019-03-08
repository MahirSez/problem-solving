#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pip 	pair<int,pii>
using namespace std;

ostream& operator<<(ostream & os, pll h)
{
	return os << "( " << h.uu << ", " << h.vv << " )" << endl;

}
pll operator+ (pll a, ll x)     {return {a.uu + x, a.vv + x} ;}
pll operator- (pll a, ll x)     {return {a.uu - x, a.vv - x} ;}
pll operator* (pll a, ll x)     {return {a.uu * x, a.vv * x} ;}
pll operator+(pll x, pll y) { return {x.uu + y.uu,x.vv + y.vv} ;}
pll operator-(pll x,pll y) { return {x.uu - y.uu, x.vv - y.vv} ;}
pll operator*(pll x,pll y) { return {x.uu * y.uu , x.vv * y.vv} ;}
pll operator%(pll x,pll y) { return {x.uu % y.uu, x.vv % y.vv} ;}

const pll p = {15485867,32452843};

const pll  mod = {1000000021, 1e9 + 9 };

string str ,tmp;
pll p_pow[MAX] , h1[MAX] ;
int ans[MAX] ;
int n;


pll getForHash(int id , int len) {

    pll tmp= (h1[id+len-1] + mod - h1[id-1]) %mod;

    tmp = (tmp *p_pow[MAX-1-id] )%mod;
    return tmp;
}



int one[MAX] , zero[MAX];
vector<pip>v;
int a , b;
int main()
{

    cin>>tmp>>str;
    if( tmp.size() < str.size()) {
		cout<<tmp<<endl;
		return 0;
    }

    n = str.size();

    for(int i =0 ; i < tmp.size() ; i++ ) {

        if( tmp[i] =='0') a++;
        if( tmp[i] =='1') b++;
    }

	for(int i =0 ; i < str.size() ; i++ ) {
		zero[i+1] = (str[i]=='0');
        one[i+1] = (str[i]=='1');
	}

    for(int i = str.size() ; i>=0 ; i--) {
        one[i] += one[i+1];
        zero[i] += zero[i+1];
    }


	if( zero[0] > a || one[0] > b) {
		cout<<tmp<<endl;
		return 0;
	}

    p_pow[0] = {1,1};
    for(int i =1 ; i < MAX; i++) {
        p_pow[i] = (p_pow[i-1] * p)%mod;
    }

    for(int i = 0 ; i < n ; i++ ) {
        h1[i+1] = (h1[i] + p_pow[i]* (int)str[i])%mod;
    }


    int tgtId = -1 ;
    int tgtOne =0, tgtZero=0;

    for(int i =1 ; i<n ; i++ ) {
        if(getForHash(1 , i) == getForHash(n-i+1 , i) ) {

//			cout<<i<<endl;
			tgtId = i;
            tgtOne = one[i+1];
            tgtZero = zero[i+1];
//            break;
        }
    }
//
//    cout<<a<<" "<<b<<endl;
//    cout<<tgtId<<" "<<n<<endl;
//    cout<<tgtZero<<" "<<tgtOne<<endl;

//    return 0;

	if( tgtId ==-1 ) {

		tgtOne = one[0];
		tgtZero = zero[0];
        while(tgtOne <=b && tgtZero <=a ) {
            cout<<str;
			b-=tgtOne;
			a-=tgtZero;
        }

        while( a >0) {
			cout<<0;
			a--;
		}
		while( b>0) {
			cout<<1;
			b--;
		}
		cout<<endl;

		return 0;
	}

//	cout<<tgtId<<" "<<tgtOne<<" "<<tgtZero<<endl;
    cout<<str;


    for(int i =0 ; i < str.size() ; i++ ) {
		if( str[i] =='0') a--;
		else b--;
    }


    while( tgtOne <= b && tgtZero <=a) {
        for(int i = tgtId ; i < str.size() ; i++ ) {
			cout<<str[i];
        }
        b-=tgtOne;
        a-=tgtZero;
    }

    while( a >0) {
		cout<<0;
		a--;
    }
    while( b>0) {
		cout<<1;
		b--;
    }
    cout<<endl;


    return 0;
}

/*
1111100
1101
*/
