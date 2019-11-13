#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

bool solve(ll n, ll m) {

    set<ll>st;
    for(int i =0 ; i< 500 ; i++ ) {
        
        ll tmp = (n/2)*3;
        st.insert(tmp);
        n = tmp;
    }
    
    if(st.size() == 1 && *st.begin() == m)  return 1;
    return (st.size() > 1);
}


int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        
        ll n , m;
        cin>>n>>m;
        bool ok = solve(n, m );
        if(n >=m || ok) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}