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

        // n = 100 , k = 500;

        vector<int>vec(n);
        // for(int i =0; i <n ; i++ ) vec[i] = i+1;
        for(int i =0; i <n ; i++ ) cin>>vec[i];

        int pos = 0;
        while(pos < n -1 && k > 0) {
            
            pos = 0;
            for(int i =0; i < n-1 ; i++ ) {
                if(vec[i] >= vec[i+1]) pos = i+1;
                else {
                    vec[i]++;
                    break;
                }
            }

            // for(auto x : vec) cout<<x<<" ";
            // cout<<'\n';
            k--;
        }
        if(pos == n-1) cout<<-1<<'\n';
        else cout<<pos+1<<'\n';
    }
    return 0;
}