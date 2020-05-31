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

int mark[MAX];

vector<int>prm ;

void seive() {
    for(ll i = 2 ; i*i < MAX ; i++) {
        if(mark[i]) continue;
        for(ll j = i*i ; j < MAX ; j += i) {
            mark[j] = 1;
        }
    }    
    for(int i = 2 ; i < MAX ; i++ ) {
        if(mark[i]) continue;
        prm.push_back(i);
    }
}


int main()
{
    fastRead;
    seive();
    ll n;
    cin>>n;
    vector<ll>vec;
    
    for(auto x : prm) {
        if(n%x) continue;
        
        int cnt = 0;
        while(n%x ==0) {
            n/=x;
            cnt++;
        }
        vec.push_back(cnt);
    }
    
    if(n != 1) vec.push_back(1);
    
    vector<ll>rec;
    for(ll i = 0 ; i < MAX ; i++ ) {
        rec.push_back(i*(i+1)/2);
    }
    
    ll ans = 0;
    for(auto x : vec) {
        
        int id = upper_bound(rec.begin() , rec.end() , x) - rec.begin() - 1;
        ans += id;

//        cout<<x<<'\n';
    }
    
    cout<<ans<<'\n';
    return 0;
    
}