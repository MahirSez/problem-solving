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

        ll sum = 0;
        int ok = 1;

        for(int i =0; i <n ; i++ ) {
            ll val;
            cin>>val;
            val += sum;
            sum = val - i;
            if(sum < 0 ) ok = 0;
        }
        cout<<(ok ? "YES\n" : "NO\n");
    }
    cout<<'\n';
}