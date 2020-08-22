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
    int n;
    cin>>n;
    vector<int>typ(n+1) , frm(n+1) , deg(n+1) , hotel;

    for(int i =1 ; i <=n ; i++ ) {
        cin>>typ[i];
        if(typ[i]) hotel.push_back(i);
    }
    for(int i =1 ; i <=n ; i++ ) {
        cin>>frm[i];
        deg[frm[i]]++;
    }
    vector<int>ans;

    for(auto x : hotel) {
        vector<int>tmp;
        int now = x;
        while(1) {
            tmp.push_back(now);
            now = frm[now];
            if(now == 0 || deg[now] > 1 ) break;
        }
        if(tmp.size() > ans.size()) ans = tmp;
    }
    reverse(ans.begin() , ans.end());
    cout<<ans.size()<<'\n';
    for(auto x : ans) cout<<x<<" ";
    cout<<'\n';


    return 0;
}