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
int taken[N];

int main()  {
    fastio;

    int k;
    cin>>k;
    int rem = 7;

    int ans = 0;

    while(++ans) {

        rem %= k;

        if(rem == 0) {
            cout<<ans<<'\n';
            return 0;
        }
        if(taken[rem]) break;

        taken[rem] = 1;
        rem *= 10;
        rem += 7;
    }
    cout<<-1<<'\n';
    return 0;
    
}