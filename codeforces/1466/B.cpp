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
        vector<int>vec(n+1);
        for(int i =0 ;i < n; i++ ) cin>>vec[i];
        vec[n] = 1e9;

        for(int i =n-1 ; i  >=0 ; i--) {
            if(vec[i] + 1 < vec[i+1] ) vec[i]++;
        }

        // for(auto x : vec) cout<<x<<" ";
        // cout<<'\n';

        set<int>s;

        for(int i = 0 ; i < n ; i++ ) s.insert(vec[i]);
        cout<<s.size()<<'\n';
    }
    return 0;

}