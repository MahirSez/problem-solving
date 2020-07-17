#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;
int ara[3];
int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        cin>>ara[0]>>ara[1]>>ara[2];
        sort(ara, ara + 3);
        if(ara[2] != ara[1]) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        cout<<ara[0]<< " "<<ara[0]<<" "<<ara[2]<<'\n';
    }
    return 0;
}