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
ll ans[MAX];
int main()
{
    fastRead;
    for(int i =0 ; i < MAX ; i++ ) {
        ans[i] = (4LL*(2*i-1) + 4 )*i + ans[i-1] ;
    }
//    for(int i =0 ; i <=10 ; i++ ) cout<<ans[i]<<'\n';
//    return 0;
    
    int t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        cout<<ans[n/2]<<'\n';
    }
    return 0;
}