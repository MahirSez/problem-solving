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

const pll p = {103,101};

const pll  mod = {1000000021, 1e9 + 9 };

string str ;

ll ans ;

pll forH , bacH , power;

int main()
{
    fastRead;
    cin>>str;
    power = {1 , 1};
    vector<ll>dp(str.size()+5);

    for(int i = 1; i <= str.size() ; i++ ) {

        forH = (forH + power*str[i-1])%mod;
        bacH = ( p*bacH + str[i-1] )%mod;

        power = (p*power)%mod;

        if( forH == bacH ) {
            dp[i] = dp[i/2]+1;
        }
        ans += dp[i];
    }
    cout<<ans<<endl;
    return 0;
}

