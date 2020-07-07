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
    vector<int>vec(n);
    for(auto &x: vec) cin>>x;
    
    sort(vec.rbegin(), vec.rend());
    
    ll ans = 0;
    
    int nn = 1;
    
    ans += vec[0];
    
    for(int i = 1 ; i < n && nn < n-1 ; i++) {
        
        ans += vec[i];
        nn++;
//        cout<<nn<<" "<<vec[i]<<" "<<ans<<'\n';
        if(nn == n-1 ) break;
        
        ans += vec[i];
        nn++;
    }
    
    cout<<ans<<'\n';
    return 0;
}