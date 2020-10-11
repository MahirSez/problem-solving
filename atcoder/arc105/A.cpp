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
int ara[10];

int solve(int id , int taken , int tgt) {
    if(id == 5) return taken == tgt;
    return ( solve(id+1, taken + ara[id] , tgt) | solve(id+1 , taken , tgt) );

}

int main()  {
    fastio;
    int tot = 0;

    for(int i = 1; i <= 4 ; i++ ) cin>>ara[i] , tot += ara[i];
    if(tot%2) {
        cout<<"No\n";
        return 0;
    }

    int ok = solve(1 , 0 , tot/2)<<'\n';
    
    if(ok) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
    
    
}