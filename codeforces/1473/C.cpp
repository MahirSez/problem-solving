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

        vector<int>ans;

        for(int i =1 ; i <= k ; i++ ) ans.push_back(i);

        for(int i = k-1 ; ans.size() < n ; i--) ans.push_back(i);


        int mid = ans.back();

        // for(int i = k-1, j = mid ; i < n ; i++, j++ ) ans[i] = j;

        for(int i = k-1 , j = mid ; j <= k ; j++, i--) ans[i] = j;

        for(int i =0 ;i < k ; i++ ) cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
}