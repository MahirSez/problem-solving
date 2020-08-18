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
    vector<pll>vec(n);
    vector<ll>cpy(n);
    for(int i = 0 ; i < n ; i++ ) {
        cin>>vec[i].uu;
        vec[i].vv = vec[i].uu;


        cpy[i] = vec[i].uu;
    }


    vector<ll>rec;
    
    while(vec.size()) {
        vector<ll>tmp1 ;
        vector<pll> tmp2;

        for(auto x : vec) {
            if(x.uu%2) tmp1.push_back(x.vv);
            else tmp2.push_back({x.uu/2 , x.vv});
        }

        if(tmp1.size() > rec.size() ) rec = tmp1;
        vec = tmp2;    
    }
    map<ll , int>mp;

    for(auto x : rec) mp[x] = 1;

    vector<ll>ans;
    for(auto x : cpy) {
        if(mp[x] == 0 )  ans.push_back(x);
    }

    cout<<ans.size()<<'\n';
    for(auto x : ans) cout<<x<<" ";
    cout<<'\n';
    return  0;


}