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
#define MAX     	6000
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int ara[MAX];

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

string str ,rev;
pll p_pow[MAX] , h1[MAX] , h2[MAX];
int ans[MAX] , dp[MAX][MAX];
int n;


pll getForHash(int id , int len) {

    pll tmp= (h1[id+len-1] + mod - h1[id-1]) %mod;

    tmp = (tmp *p_pow[MAX-1-id] )%mod;
    return tmp;
}

pll getBacHash(int id , int len) {

    pll tmp= (h2[id+len-1] + mod - h2[id-1])%mod;
    tmp = (tmp * p_pow[MAX-1-id])%mod;
    return tmp;
}

int main()
{
    cin>>str;
    rev = str;
    n = str.size();
    reverse(rev.begin() , rev.end());
    p_pow[0] = {1,1};
    for(int i =1 ; i < MAX; i++) {
        p_pow[i] = (p_pow[i-1] * p)%mod;
    }

    for(int i = 0 ; i < n ; i++ ) {
        h1[i+1] = (h1[i] + p_pow[i]* (int)str[i])%mod;
    }
    for(int i = 0 ; i < n ; i++) {
        h2[i+1] = (h2[i] + p_pow[i]*(int)rev[i])%mod;
    }

    ans[1] = n;
    for(int i = 1 ; i<= n ; i++) dp[i][i] = 1;

    for(int i =2 ; i <= n; i++ ) {

        for(int j =1 ; j  +i -1 <= n ; j++) {

            int midLen = i/2;

            int id1 = j , id2 = j + i - 1;
            id2 = n-id2 + 1;

            if( getForHash(id1 , midLen) == getBacHash(id2 , midLen)  ) {

                dp[j][j+i-1] = dp[id1][id1+midLen-1] + 1;
                ans[dp[j][j+i-1]]++;
            }
        }
    }
    for(int i = n-1 ; i >=1 ; i--) {
        ans[i]+= ans[i+1];
    }

    for(int i = 1; i<= n ; i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
