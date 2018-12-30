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
using namespace std;

ostream& operator<<(ostream & os, pll h) {
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

pll p_pow[MAX] , h[MAX];

int ara[MAX] , tmp[MAX];
map<int,int>mp;
int tot , n;

vector<int>edg[MAX];
vector<pii>rec;

pll getHash(int id , int len) {

    pll tmp = (h[id+len-1] + mod - h[id-1])%mod;
    tmp = (tmp * p_pow[MAX-1-id])%mod;
    return tmp;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i = 0 ; i < n ; i ++) cin>>ara[i] , tmp[i] = ara[i];

    for(int i =0 ; i < n ; i++ ) {

        if(mp.count(ara[i]) ==0 ) {

            mp[ara[i]] = ++tot;
        }
        ara[i] = mp[ara[i]];
    }

    for(int i = 0; i < n ; i++) {
        edg[ara[i]].push_back(i+1);
    }

    p_pow[0] = {1,1};
    for(int i = 1 ; i<MAX ; i++) {
        p_pow[i] = (p_pow[i-1]*p)%mod;
    }

    for(int i = 0 ; i < n ; i++ ) {
        h[i+1] = (h[i] + p_pow[i]*ara[i])%mod;
    }

    for(int i =1 ; i<= tot; i++ ) {

        for(int j =0 ; j < edg[i].size() ; j++ ) {

            for(int k =j+1 ; k < edg[i].size() ; k++ ) {


                int id1 = edg[i][j];
                int id2 = edg[i][k];

                int len = id2 - id1;

                if( n - id2 + 1 < len) continue;

                if( getHash(id1 , len) == getHash(id2 , len) ) {
                    rec.push_back({ len, id1});
                }
            }
        }
    }

    sort( rec.begin() , rec.end() ) ;

    int frm = 1;

    for(int i = 0 ; i < rec.size() ; i++ ) {

        int len = rec[i].uu;
        int pos = rec[i].vv;
//        cout<<len<<" "<<pos<<endl;

        if( pos < frm ) continue;

        frm = pos + len;
    }
    frm--;

    cout<<n - frm<<endl;
    for(int i = frm ; i < n ; i++ )
        cout<<tmp[i]<<" ";
    cout<<endl;
    return 0;

}




