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
        int n , m;
        cin>>n>>m;
        n*=3;
        vector<int>taken(n+1);
        vector<tp>edg , matching;

        for(int i =0 ; i < m ; i++ ) {
            int u , v;
            cin>>u>>v;
            edg.push_back({i+1 , u,v});
        }

        for(auto x : edg) {
            int u , v , id;
            tie(id , u , v) = x;
            if(taken[u] || taken[v]) continue;
            taken[u] = 1;
            taken[v] = 1;
            matching.push_back(x);
        }
        if(matching.size() >= n/3) {
            cout<<"Matching\n";
            for(int i =0 ; i < n/3 ; i++ ) cout<<get<0>(matching[i])<<" ";
            cout<<'\n';
            continue;
        }

        vector<int>baki;
        for(int i =1 ; i<=n ; i++ ) {
            if(taken[i] ==0) baki.push_back(i);
        }
        assert(baki.size() >=n/3);
        cout<<"IndSet\n";
        for(int i = 0 ; i < n/3 ; i++ ) cout<<baki[i]<<" ";
        cout<<'\n';
        
    }
    
    return  0;
}