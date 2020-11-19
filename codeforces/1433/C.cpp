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
    while(t--)   {
        int n;
        cin>>n;
        vector<int>vec(n);
        int mx = 0;
        for(int i =0 ; i < n ; i++ ) cin>>vec[i], mx = max(mx, vec[i]);

        int id = -1;
        for(int i = 0 ; i < n ; i++ ) {
            if(vec[i] != mx) continue;

            if(i > 0 && vec[i-1] < vec[i]) id = i+1;
            if(i < n-1 && vec[i+1] < vec[i]) id = i+1;
        
        }
        cout<<id<<'\n';
    }
    return 0;
}