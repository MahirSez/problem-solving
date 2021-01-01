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

        ll sum = 0;

        vector<int>vec(n), deg(n);

        for(int i =0; i <n ; i++ ) {
            cin>>vec[i];
            sum += vec[i];
        }

        for(int i = 0; i < n-1 ; i++ ) {
            int u, v;
            cin>>u>>v;
            u--, v--;
            deg[u]++;
            deg[v]++;
        }
        priority_queue<pll>pq;
        for(int i =0 ;i < n ; i ++ ) {
            if(deg[i] > 1) pq.push({vec[i], deg[i]-1});
        }
        
        cout<<sum<<" ";
        for(int i = 0 ; i < n -2 ; i++ ) {

            assert(!pq.empty()) ;
            pll top = pq.top();
            pq.pop();
            ll val = top.uu;
            ll fre = top.vv-1;

            sum += val;
            cout<<sum<<" ";
            if(fre) pq.push({val, fre});
        }
        cout<<'\n';
    }
    return 0;

}