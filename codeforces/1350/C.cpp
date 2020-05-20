#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = sqrt(2e5 + 5) + 100;
vector<int>prm , rec[1000006];
int mark[MAX];

void seive() {

    
    for(ll i =2 ; i *i < MAX ; i++) {
        
        if(mark[i]) continue;
        for( ll j = i *i ; j < MAX ; j+=i ) {
            mark[j] = 1;
        }
    }
    for(int i = 2; i < MAX ; i++ ) {
        if(mark[i] == 0) prm.push_back(i);
    }
}
int main()
{
    seive();
    fastRead;
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i =0 ; i < n ; i++ ) cin>>vec[i];
    
    for(auto x : vec) {
        
        for(auto xx : prm) {
            int cnt = 0;
            while(x%xx ==0 ) {
                cnt++;
                x/=xx;
            }
            rec[xx].push_back(cnt);
        }
        rec[x].push_back(1);
    }
    
    for(int i =0 ; i < 1000006; i++ ) {
        if(rec[i].size() < n-1) rec[i].clear();
        else if(rec[i].size() == n-1) rec[i].push_back(0);
        
    }
    
    
    ll ans = 1;
    for(int i =2 ; i < 1000006 ; i++ ) {
        if(rec[i].size() == 0) continue;
        
        sort(rec[i].begin() , rec[i].end());
        
        ll tgt = 1;
        while(rec[i][1]--) tgt*=i;
        ans *=tgt;
    }
    
    cout<<ans<<'\n';
    return 0;
    
}