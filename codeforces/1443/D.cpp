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
        vector<int>vec(n);
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        if(n <= 2) {
            cout<<"YES\n";
            continue;
        }

        int till = 0;


        for(int i = 1 ; i < n  ; i++ ) {

            if(vec[i] <= vec[i-1]) {
                till = i;
                continue;
            }
            else break;
        }

        int tmp = vec[till];

        for(int i = till ; i < n-1 ; i++) {
            if(vec[i] <= vec[i+1]) continue;

            int diff = vec[i] - vec[i+1];
            tmp -= diff;
            
        }



        if(tmp >= 0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}