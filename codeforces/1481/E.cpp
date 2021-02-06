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

    int n;
    cin>>n;
    vector<int>dp(n+1) , vec(n), fre(n+1), tot(n+1), r(n+1);
    for(int i =0; i <n ; i++ ) cin>>vec[i], tot[vec[i]]++;


    for(int i = n-1; i>=0 ; i-- ) {
        fre[vec[i]]++;
        if(fre[vec[i]] == 1) r[vec[i]] = i; 
        if(tot[vec[i]] == fre[vec[i]]) dp[i] =  max(dp[i+1], dp[r[vec[i]] + 1] + tot[vec[i]]);
        else dp[i] = max(dp[i+1], fre[vec[i]]);
    }

    cout<<n - dp[0]<<'\n';
    return 0;
}