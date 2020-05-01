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
    int t;
    cin>>t;
    while(t--) {
        int n, k;
        cin>>n>>k;
        vector<int>vec(n);
        
        for(int i = 0 ; i < n ; i++ ) {
            cin>>vec[i];
        }
        sort(vec.begin() , vec.end());
        vec.erase( unique(vec.begin() , vec.end()) , vec.end());
        
        if(vec.size() > k ) {
            cout<<-1<<'\n';
            continue;
        }
        while(vec.size() < k) vec.push_back(1);
        
//        for(auto x : vec) cout<<x<<" ";
//        cout<<'\n';
//        continue;
        
        int id = 0;
        while(vec.size() < k * n ) {
            
            vec.push_back(vec[id++]);
        }
        cout<<vec.size()<<'\n';
        for(auto x : vec) cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
    
}