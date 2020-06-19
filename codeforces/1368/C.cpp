#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

int main()
{
    int n;
    cin>>n;
    cout<<(n+1)*2 + n + 2<<'\n';
    
    for(int i =0 ; i <= n+1; i++ ) cout<<i<<" "<<i<<'\n';
    for(int i = 0 ; i<=n ; i++ ) cout<<i<<" "<<i+1<<'\n';
    for(int i = 0 ;i <=n ; i++ ) cout<<i+1<<" "<<i<<'\n';
    return 0;
}
