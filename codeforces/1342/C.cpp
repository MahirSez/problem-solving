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

ll a , b , q , lcm ;

ll solve(ll till) {
    till++;
    
    ll cnt = (till/lcm) * ( lcm - a );
    ll extra = (till%lcm);
    extra = max( 0LL , extra - a);
    
    
//    cout<<cnt<<" "<<extra<<'\n';
    return  cnt + extra;
    
}

/*
1
4 8 1
1 100
*/


int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        cin>>a>>b>>q;
        if(a < b ) swap(a,b);
        lcm = a*b/__gcd(a,b);
        while(q--) {
            ll l , r;
            cin>>l>>r;
            ll ret1 = solve(r);
            ll ret2 = solve(l-1);
            cout<<ret1 - ret2<<" ";
        }
        cout<<'\n';
    }
    return 0;
    
}