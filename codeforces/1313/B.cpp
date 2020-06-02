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
    int t;
    cin>>t;
    while(t--) {
        ll n , x , y;
        cin>>n>>x>>y;
        cout<<min(n, max(1LL, x + y - n + 1) )<<" "<<max(1LL, min(n, x + y - 1))<<'\n';
    }
    return 0;
}