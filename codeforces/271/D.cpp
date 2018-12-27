#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll     	pair<ll,ll>
#define INF     	1e18
#define EPS     	1e-8
#define MAX     	2000
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string str , s;
int ln;

const int p1 = 31;
const int p2 = 37;

const int mod1 = 1e9+9;
const int mod2 = 1e9+7;

ll h1[2][MAX] ,p1_pow[MAX] , p2_pow[MAX];
bool bad[30];
int rec[MAX];
map<pll , bool>mp;



pll getHash(int id1 , int id2)
{

    ll tmp1 = (h1[0][id2]+ mod1 - h1[0][id1-1])%mod1;
    tmp1 = (tmp1 * p1_pow[MAX-1-id1])% mod1;

    ll tmp2 = (h1[1][id2]+ mod2 - h1[1][id1-1])%mod2;
    tmp2 = (tmp2 * p2_pow[MAX-1-id1])% mod2;

    return {tmp1 , tmp2};
}

int main()
{
    cin>>str>>s>>ln;
    p1_pow[0] = p2_pow[0] = 1;

    for(int i =1 ;i < MAX ; i++ ) {
        p1_pow[i] = (p1_pow[i-1] * p1) % mod1;
        p2_pow[i] = (p2_pow[i-1] * p2) % mod2;
    }

    for(int i = 0 ; i < str.size() ; i++ ) {

        h1[0][i+1] = (h1[0][i] + (str[i]-'a'+1)*p1_pow[i]) %mod1;
        h1[1][i+1] = (h1[1][i] + (str[i]-'a'+1)*p2_pow[i]) %mod2;
    }


    for(int i =0 ; i < s.size() ; i++ ) {

        if( s[i] =='0') {
            bad[i+1] = 1;
        }
    }

    for(int i =0 ; i < str.size() ; i++ ) {
        if( bad[(str[i] -'a'+1)] ) {
            rec[i+1]++;
        }
    }

    for(int i =1 ; i <= str.size() ; i++ ) {
        rec[i] += rec[i-1];
    }


    int ans = 0;

    for(int i =1 ; i <= str.size() ; i++ ) {

        for(int j = 1 ; j + i -1 <= str.size() ; j++ ) {

            int frm = j , to = j+i-1;

            if( rec[to] - rec[frm-1] > ln) continue;

            pll tmp = getHash(frm , to);

            if(mp[tmp] == false) {
                ans++;
                mp[tmp] = true;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

