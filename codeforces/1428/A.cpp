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
        int x1 , y1 , x2 , y2;
        cin>>x1>>y1>>x2>>y2;
        int dst = abs(x1 - x2) + abs(y1 - y2);
        if(x1 == x2 || y1 == y2) {
            cout<<dst<<'\n';
        }
        else cout<<dst + 2<<'\n';
    }

    return 0;
}