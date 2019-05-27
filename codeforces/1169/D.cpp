#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define ppi         pair<pii,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string str;
int main()
{
    fastRead;
    cin>>str;

    ll ans = 0;
    int n = str.size();
    int to = n;
    
    for(int i = n-1 ; i >=0 ; i--) {
        
        for(int j = 1 ; i + 2*j < to ; j++ ) {
                
            if( str[i] == str[i+j] && str[i] == str[i+2*j]) {
                to = i + 2*j;
                break;
            }
        }
        ans += n - to;
    }
    
    cout<<ans<<endl;
    return 0;
}
