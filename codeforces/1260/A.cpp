#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {

        ll c , sum;
        ll ans= 0;
        cin>>c>>sum;
        while(1) {

            ll tmp = sum/c;
            ans += tmp*tmp;
            sum -= tmp;
            c--;
            if(c == 0 ) break;
        }
        assert(sum == 0 );
        cout<<ans<<'\n';
    }
    return 0;
}
