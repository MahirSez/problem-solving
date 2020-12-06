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
        vector<int>x(n) , y(n);
        for(int i =0 ;i < n; i++ ) cin>>x[i]>>y[i];
        int ok = 0;

        for(int i =0 ; i < n ;i++ ) {
            
            int okk = 1;
            for(int j =0 ; j < n ; j++ ) {
                if(abs(x[j] - x[i]) + abs(y[j] - y[i]) > k) okk = 0;
            }
            if(okk) ok = 1;
        
        }

        if(ok ==0) cout<<-1<<'\n';
        else cout<<1<<'\n';
    }
    return 0;
}