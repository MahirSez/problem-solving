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
        int n, m;
        cin>>n>>m;
        set<ll>s;
        vector<ll>vec(n+1), sum(n+1);
        for(int i =1 ; i <=n ;i++ ) {
            cin>>vec[i];
        }
        sort(vec.begin() , vec.end());
        for(int i = 1 ; i<=n ; i++) {
            sum[i] = sum[i-1] + vec[i];
        }
        

        queue<pii>q;

        q.push({1,n});

        while(!q.empty()) {

            int l = q.front().uu;
            int r = q.front().vv;
            q.pop();

            s.insert(sum[r] - sum[l-1]);

            if(vec[l] == vec[r]) continue;
            ll mid = (vec[l] + vec[r])/2;

            int id = upper_bound(vec.begin() , vec.end() , mid) - vec.begin()-1;

            // cout<<l<<" "<<r<<" "<<id<<'\n';

            q.push({l, id});
            q.push({id+1, r});
            
        }
        // for(auto x : s) cout<<x<<" ";
        // cout<<'\n';
        while(m--) {
            ll x;
            cin>>x;
            if(s.find(x) != s.end()) cout<<"Yes\n";
            else cout<<"No\n";

        }

        
        
    }
    return 0;
}


/*
1
5 0
1 2 3 4 5
*/