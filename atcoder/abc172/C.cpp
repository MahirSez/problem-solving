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
int main()
{
    fastRead;
    ll n, m, k;
    cin>>n>>m>>k;
    vector<ll>sum1(n+1);
    vector<ll>sum2(m+1);
    
    for(int i = 1; i <=n ; i++ ) cin>>sum1[i], sum1[i] += sum1[i-1];
    for(int i = 1; i <=m ; i++ ) cin>>sum2[i], sum2[i] += sum2[i-1];
    
    int ans = 0;
    
    for(int i = 0 ; i <=n ; i++ ) {
        
        if(sum1[i] > k) break;
        
        ll baki = k - sum1[i];
        
        int id = upper_bound(sum2.begin()+1, sum2.end(), baki) - sum2.begin()-1;
        ans = max(ans, i + id);
    }
    cout<<ans<<'\n';
    return 0;
}