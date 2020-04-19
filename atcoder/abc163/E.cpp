#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;


const int MAX = 2000 + 3;
ll dp[MAX][MAX];
int n;
vector<pll>vec;

ll solve(int l , int r , int id) {

    if(id == n ) return 0;
    
    ll &ret = dp[l][r];
    if( ret != -1 ) return ret;
    
    ll tmp1 = solve(l+1 , r , id+1) + vec[id].uu * abs(vec[id].vv - l);
    ll tmp2 = solve(l , r-1 , id+1) + vec[id].uu * abs(vec[id].vv - r);
    
    ret = max(tmp1 , tmp2);
    return ret;
    
    
    
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        ll val;
        cin>>val;
        vec.push_back({val , i});
    }
    sort(vec.rbegin() , vec.rend());
    
    memset(dp , - 1,  sizeof dp);
    cout<<solve(0 , n-1 , 0)<<'\n';
    return 0;
    
}
