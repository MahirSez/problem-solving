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
#define MAX     	5000006
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

string str ,rev;
pll p_pow[MAX] , h2[MAX] , h1;

int rec[MAX] , n;

ll ans ;

int main()
{
    fastRead;
    cin>>str;
    rev = str;
    reverse(rev.begin() , rev.end());
    n = str.size();
    p_pow[0] = {1,1};

    for(int i =1 ; i < MAX ; i++) {
        p_pow[i] = (p_pow[i-1]*p)%mod;
    }

    for(int i =0 ; i < str.size() ; i++ ) {
        h2[i+1] = (h2[i] + p_pow[i]*(int)rev[i])%mod;
    }

    rec[1] = 1;
    ans = 1;
    h1 = (p_pow[0] * (int)str[0])%mod;

    for(int i =2 ; i<= n ;i++ ) {

        h1 = (h1 + p_pow[i-1]*(int)str[i-1] )%mod;

        pll tmp = (h1 * p_pow[MAX-2])%mod;
        int id = n - i + 1;

        if( tmp == ( ( ( h2[n]+mod-h2[id-1] )%mod )* p_pow[MAX-1-id] )%mod ) {
            rec[i] = rec[i/2]+1;
        }
        ans += rec[i];

    }

    cout<<ans<<endl;
    return 0;
}
