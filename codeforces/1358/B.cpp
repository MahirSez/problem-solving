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
    while(t--) {
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        sort(vec.begin() , vec.end());
        
        int ans = 0 , cnt = 1;
        
        for(auto x : vec) {
            if(cnt >= x) ans = cnt;
            cnt++;
        }
        cout<<ans+1<<'\n';
    }
    return 0;
    
}