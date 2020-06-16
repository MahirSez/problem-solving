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

ll ask(vector<ll>&vec) {
    if(vec.size() == 0 ) return 0;
    cout<<"? "<<vec.size()<<" ";
    for(auto x: vec) cout<<x<<" ";
    cout<<endl;
    ll ret;
    cin>>ret;
    return ret;
}


int main()
{
    int n;
    cin>>n;
    ll now= 0;
    
    vector<ll>rec, orbit(20), ans(n);
    
    while(rec.size() < n) {
        if(__builtin_popcount(now) == 5) {
            rec.push_back(now);
//            cout<<now<<'\n';
        }
        now++;
    }
    
    for(int i =0 ; i < 13; i++ ) {
        vector<ll>tmp;
        for(int j =0 ; j < n ; j++ ) {
            if(rec[j] & (1LL<<i)) tmp.push_back(j+1);
        }
        orbit[i] = ask(tmp);
    }
    
    for(int i =0 ; i < n ; i++) {
        
        for(int j=0 ; j < 13 ; j++ ) {
            if( !(rec[i] & (1LL<<j)) ) ans[i] |= orbit[j];
        }
    }
    cout<<"! ";
    for(auto x : ans) cout<<x<<" ";
    cout<<endl;
    
    return 0;
}