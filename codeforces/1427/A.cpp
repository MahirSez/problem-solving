#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;
    
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>vec(n) , p , ne , z;
        int pos = 0 ,neg = 0;


        for(int i =0 ; i < n ; i++ ) {
            cin>>vec[i];
            if(vec[i] > 0) {
                pos += vec[i];
                p.push_back(vec[i]);
            }
            else if(vec[i] < 0 ){
                neg += abs(vec[i]);
                ne.push_back(vec[i]);
            }
            else z.push_back(0);
        }

        if(pos == neg) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        if(neg > pos) swap(p , ne);
        for(auto x : p) cout<<x<<" ";
        for(auto x : ne) cout<<x<<" ";
        for(auto x : z) cout<<x<<" " ;
        cout<<'\n';

    }
    return 0;
    
}