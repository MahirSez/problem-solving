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
    int n , k;
    cin>>n>>k;
    vector<int>cnt(n+1);
    
    while(k--) {
        
        int tmp;
        cin>>tmp;
        while(tmp--) {
            int x;
            cin>>x;
            cnt[x]++;
        }
    }
    
    int ans = 0;
    for(int i =1; i <=n ; i++ ) {
        if(cnt[i] == 0 ) ans++;
    }
    cout<<ans<<'\n';
    return 0;
    
    
}