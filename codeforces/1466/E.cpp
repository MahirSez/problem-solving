#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

const int M = 62; 

int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        

        vector<ll>fre(100), vec(n);
        for(int i =0; i <n ; i++ ) {
            cin>>vec[i];

            for(int j =0 ;j < M ; j++) {
                if(vec[i] & (1LL<<j)) fre[j]++;
            }
        }

        ll ans = 0;
        for(int i =0 ;i <n ; i++ ) {

            ll andsum = 0, orsum = 0;

            for(int j =0; j < M ; j++ ) {
                ll tmp1 = (1LL<<j) % MOD ;

                if(vec[i] & (1LL<<j) ) {    
                    andsum +=  ( ( tmp1 * fre[j] ) %MOD );
                    orsum += ( ( tmp1 * n ) %MOD );
                }
                else orsum += ( ( tmp1 * fre[j] ) %MOD );

                andsum %= MOD;
                orsum %= MOD;
            }

            // cout<<andsum<<" "<<orsum<<'\n';
            
            ans += andsum * orsum;
            ans %= MOD;
        }
        cout<<ans<<'\n';
    }
    return 0;
}