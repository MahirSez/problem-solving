#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         2e9
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
        vector<pii>vec(n);
        for(int i = 0 ; i < n; i++ ) {
            cin>>vec[i].uu;
            vec[i].vv = i;
        }
        sort(vec.begin(), vec.end());
        int last = -1;
        int cnt = 0, mx = 0;
        
        for(auto x: vec) {
            if(x.vv > last) cnt++;
            else cnt = 1;
            
            last = x.vv;
            mx = max(mx, cnt);
        }
        cout<<n-mx<<'\n';
    }
    return 0;
}