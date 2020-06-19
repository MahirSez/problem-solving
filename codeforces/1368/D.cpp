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
    vector<int>fre(30);
    for(int i =0 ; i < n ;i++ ) {
        int tmp;
        cin>>tmp;
        for(int j = 0 ; j < 25 ; j++ ) {
            if(tmp & (1<<j)) fre[j]++;
        }
    }
    
    ll ans = 0;
    
    for(int i =1 ; i <= n ; i++ ) {
        
        ll tmp = 0;
        for(int j =0 ; j < 25 ; j++ ) {
            if(fre[j] >= i ) tmp |= (1<<j);
        }
        ans += tmp * tmp;
    }
    cout<<ans<<'\n';
    return 0;
}