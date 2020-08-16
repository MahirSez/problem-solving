#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;
    int n , d;
    cin>>n>>d;
    d--;
    vector<int>pt(n);
    vector<pii>vec(n);
    for(int i =0 ; i < n ; i++ ) {
        cin>>vec[i].uu;
        vec[i].vv = i;
    }
    for(int i =0 ; i < n ; i++ ) cin>>pt[i];

    vec[d].uu += pt[0];
    int tgt = vec[d].uu;

    int id = n-1;
    int ans = 1;
    for(int  i = 0  ; i < d ; i++ ) {
        
        if(vec[i].uu + pt[id] <= tgt) {
            id--;
        }
        else ans++;
    }
    
   
    cout<<ans<<'\n';
    return 0;
    
    
}