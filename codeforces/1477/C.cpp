#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

struct pt {
    int id;
    int x, y;
};

double distSqr(pt p1, pt p2) {
    double dx = (p1.x - p2.x);
    double dy = (p1.y - p2.y);
    return dx*dx + dy*dy;
}
int main()  {
    fastio;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    int n;
    cin>>n;

    vector<pt>vec(n);
    for(int i =0; i <n ; i++ ) {
        cin>>vec[i].x>>vec[i].y;
        vec[i].id = i+1;
    }

    vector<pt>ans;
    ans.push_back(vec[0]);
    vector<int>vis(n+1);
    vis[1] = 1;

    for(int i =0 ; i < n-1 ; i++ ) {

        ll dist = 0;
        pt tgtpt;
        tgtpt.id = -1;
        for(auto x : vec) {
            if(vis[x.id]) continue;

            ll tmpdist = distSqr(ans.back(), x);
            if(tmpdist > dist) {
                dist = tmpdist;
                tgtpt = x;
            }
        }

        assert(tgtpt.id != -1);
        ans.push_back(tgtpt);
        vis[tgtpt.id] = 1;
    }

    for(auto x : ans) cout<<x.id<<" ";
    cout<<'\n';

    return 0;
}