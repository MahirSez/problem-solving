#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

ll ara[6000];

int main()
{
    fastRead;
    int n;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    
    ll ans = 0;
    for(int i =0 ; i < n ; i++ ) {
        for(int j =0 ; j < n ; j++ ) {
            for(int k = 0 ; k < n ;k++ ) {
                ll tmp = (ara[i] | ara[j] | ara[k]);
                ans = max(ans, tmp);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
    
    
}