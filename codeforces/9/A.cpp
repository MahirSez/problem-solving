#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int n , m;
    cin>>n>>m;
    n = max(n , m);
    int up = (6 - n+1);
    int down = 6;
    int gcd = __gcd(up , down);
    up /= gcd;
    down /=gcd;
    cout<<up<<"/"<<down<<'\n';
    return 0;
    
}