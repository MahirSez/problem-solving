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

const ll MAX = 1e5 + 6;

vector<ll>prm;
int mark[MAX];

void seive() {

    for(ll i =2 ; i*i < MAX ; i++) {
        if(mark[i]) continue;
        
        for(ll j = i*i  ; j < MAX ; j+=i) mark[j] = 1;
    }
    
    for(int i =2;  i < MAX ; i++ ) {
        if(mark[i]==0) prm.push_back(i);
    }
}
int main()
{
    fastRead;
    seive();
    
    
    int t;
    cin>>t;
    while(t--) {
        
        ll n;
        cin>>n;
        vector<ll>ret;
        
        for(int i =0 ; i < prm.size() && ret.size() < 2 ; i++ ) {
            ll tmp = prm[i];
            
            if(n%tmp) continue;
            n/=tmp;
            ret.push_back(tmp);
        }
        
        if(ret.size() == 2 && n!= 1 && n!= ret[0] && n != ret[1]) {
            cout<<"YES\n";
            cout<<ret[0]<<" "<<ret[1]<<" "<<n<<'\n';
            continue;
        }
        
        if(ret.size() ==0 ) {
            cout<<"NO\n";
            continue;
        }
        
        int tmp = ret[0] * ret[0];
        
        if(n % tmp) {
            cout<<"NO\n";
            continue;
        }
        
        n/=tmp;
        
        
        if( n!= 1 && n != ret[0] && n != tmp ) {
            cout<<"YES\n";
            cout<<ret[0]<<" "<<tmp<<" "<<n<<'\n';
        }
        else cout<<"NO\n";
        
    }
    return 0;
    
}