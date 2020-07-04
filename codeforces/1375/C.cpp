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
        int n, mx = 0;
        cin>>n;
        vector<int>vec(n);
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        
        int ok = 1;
            
        for(int i = n -1 ; i >= 1 ;i--) {

            if(vec[i] < vec[0] && vec[i] > mx) ok = 0;
            mx = max(mx, vec[i]);
        }
        if(ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}