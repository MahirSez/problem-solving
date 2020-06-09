#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

int mark[MAX];
vector<int>prm;

void seive() {
    
    for(ll i = 2 ; i *i < MAX ; i++) {
        if(mark[i]) continue;
        for(ll j = i*i ; j < MAX ; j += i) mark[j] = 1;
    }
    
    for(int i = 2; i < MAX ; i++ ) {
        if(mark[i]) continue;
        prm.push_back(i);
    }
}

int main()
{
    fastRead;
    seive();
    ll x;
    cin>>x;
    
    vector<ll>rec;
    
    for(auto xx : prm) {
        if(x % xx ) continue;
        ll tmp = 1;
        while(x % xx == 0) {
            tmp *=xx;
            x /= xx;
        }
        rec.push_back(tmp);
    }
    if(x != 1) rec.push_back(x);
//    
//    for(int i =0 ; i <rec.size(); i++ ) {
//        cout<<rec[i]<<" ";
//    }
//    cout<<'\n';
    
    int n = rec.size();
    
    ll ans1 = INF, ans2 = INF;
    
    for(int i =0 ; i < (1<<n) ; i++ ) {
        
        int mask = i;
        ll tmp1 = 1, tmp2 = 1;
        
        for(int j =0 ; j < n ; j++ ) {
            
            if(mask & (1<<j)) tmp1 *= rec[j];
            else tmp2 *= rec[j];
        }
        if(max(tmp1, tmp2) < max(ans1, ans2)) {
            ans1 = tmp1;
            ans2 = tmp2;
        }
    }
    cout<<ans1<<" "<<ans2<<'\n';
    
    return 0;
    
    
    
}