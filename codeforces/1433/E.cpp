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
ll ara[100][100];

ll nCr(ll n , ll r) {
    if( n == r || r == 0) {
        return ara[n][r] = 1;
    }
    return  ara[n][r] = nCr(n-1 , r)  + nCr(n-1 , r-1 );
}

int main()  {
    fastio;  
    ll n;
    cin>>n;
    ll ans = nCr(n, n/2)/2;
    ll fact = 1;
    ll till = n/2 -1;

    // cout<<ans<<" "<<till<<" "<<'\n';

    for(int i =1 ; i <=till ; i++ ) fact *= i;
    

    ans *= fact * fact;
    cout<<ans<<'\n';


    return 0;
}