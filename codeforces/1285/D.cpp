#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

int solve(vector<int>vec, int lvl) {
    
    if(lvl == -1) return 0;
    
    vector<int>one, zero;
    for(auto x : vec) {
        if(x & (1<<lvl)) one.push_back(x);
        else zero.push_back(x);
    }
    
    if(one.size() == 0) return solve(zero, lvl-1);
    else if(zero.size() == 0) return solve(one, lvl-1);
    
    return (1<<lvl) + min( solve(one, lvl-1), solve(zero, lvl-1) );
}


int main()
{
    fastRead;
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i =0 ; i < n ; i++ ) cin>>vec[i];
    cout<<solve(vec, 30)<<'\n';
    return 0;
}