#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 3e5 + 5;

int main()
{
    fastRead;
    int n , m;
    cin>>n>>m;
    ll tot = 0;
    for(int i =0 ; i < m ; i++ ) {
        ll tmp;
        cin>>tmp;
        tot += tmp;
    }
    if(tot > n) cout<<-1<<'\n';
    else cout<<n-tot<<'\n';
    return 0;
}