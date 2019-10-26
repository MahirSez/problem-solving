#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int n , k , d , ara[MAX];

map<int,int>mp;

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t-- ) {
        cin>>n>>k>>d;
        mp.clear();
        
        for(int i = 0 ; i < n ; i++ ) {
            cin>>ara[i];
        }
        
        for(int i =0 ; i < d ; i++ ) mp[ara[i]]++;
        
        int ans = mp.size();
        int now = ans;
        
        for(int i =1 , j = d; j < n ; j++ , i++  ) {
            
            mp[ara[i-1]]--;
            if(mp[ara[i-1]] == 0 ) now--;
            
            mp[ara[j]]++;
            if(mp[ara[j]] == 1 ) now++;
            
            ans = min(ans , now);
        }
        cout<<ans<<'\n';

    }
    return 0;
}