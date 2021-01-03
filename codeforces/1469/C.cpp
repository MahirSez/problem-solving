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
        int n, k;
        cin>>n>>k;
        vector<int>vec(n, -1), v(n);
        priority_queue<pii>pq;
        for(int i =0 ; i< n ; i++ ) {
            cin>>v[i];
            pq.push({v[i], i});
        }

        while(!pq.empty()) {
            pii top = pq.top();
            int h = top.uu;
            int id = top.vv;
            pq.pop();


            if(id == 0 || id == n-1) {
                vec[id] = h;
                continue;
            }

            // cout<<h<<'\n';

            if(vec[id-1] != -1) h = max(h,  vec[id-1] - k + 1);
            if(vec[id+1] != -1) h = max(h,  vec[id+1] - k + 1);

            // cout<<id<<" "<<h<<'\n';

            vec[id] = h;
        }

        // for(int i =0 ;i < n; i++ ) cout<<vec[i]<<" ";
        // cout<<'\n';
        
        int ok = 1;

        for(int i =1 ; i <n ; i++ ) {
            if( abs( vec[i] - vec[i-1] ) >= k ) ok = 0;

            if( vec[i] - v[i] >= k) ok = 0;
        }

        cout<<(ok ? "YES" : "NO")<<'\n';

    }
}