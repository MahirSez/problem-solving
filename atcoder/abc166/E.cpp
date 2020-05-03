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
    
    int n;
    cin>>n;
    vector<int>vec(n+1) ;
    map<int,int>mp;
    ll ans = 0;
    
    for(int i =1; i <=n ; i++ ) {
        cin>>vec[i];
        mp[i-vec[i]]++;
    }
    
    for(int i =1 ;i <=n ; i++ ) {
        ans += mp[i + vec[i]];
    }
    cout<<ans<<'\n';
    return 0;

}