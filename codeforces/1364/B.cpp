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
    while(t-- ){
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        vector<int>ans;
        ans.push_back(vec[0]);
        for(int i =1 ; i < n-1 ; i++ ) {
            
            if(vec[i] > ans.back() && vec[i+1] > vec[i]) continue;
            if(vec[i] < ans.back() && vec[i+1] < vec[i]) continue;
            
            ans.push_back(vec[i]);
            
        }
        ans.push_back(vec[n-1]);
        cout<<ans.size()<<'\n';
        for(auto x : ans) cout<<x<<" ";
        cout<<'\n';
    }
}