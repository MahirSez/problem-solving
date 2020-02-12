#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

ll n , m  , ara[100] , p[100];
vector<int>baki;

ll solve() {
    
    ll ans = 0;

    for(int i =0 ; i < 70 ; i++ ) {
        
        if(ara[i]) {
            if(p[i] > 0) p[i]--;
            else baki.push_back(i);
        }
        
        if(p[i]>0 && baki.size() > 0) {
            
            ans += i - baki[0];
            
            p[i]--;
            baki.clear();
        }
        
        p[i+1] += p[i]/2;
        
    }
    
    if(baki.size() ) return -1;
    
    return ans;

}


int main()
{
    fastRead;
    
    int t;
    cin>>t;
    while(t--) {
        baki.clear();
        cin>>n>>m;
        memset(p ,0 , sizeof p);
        
        while(m-- ) {
            ll tmp;
            cin>>tmp;
            int b = 0;
            while(tmp) {
                tmp/=2;
                b++;
            }
            b--;
            p[b]++;
        }
        
        for(int i =0 ; i < 100 ; i++ ) {
            
            ara[i] = n%2;
            
            n/=2;
            
        }
        
//        for(int i =0 ; i < 10 ; i++ ) cout<<p[i]<<" ";
//        cout<<'\n';
//        
        cout<<solve()<<'\n';
    }
    return 0;
    
}   