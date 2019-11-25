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

int main()
{
    double a , b , c , d;
    cin>>a>>b>>c>>d;
    
    double ans = (a*d)/(b*d - (b-a)*(d-c) );
    cout<<setprecision(10)<<fixed<<ans<<'\n';
    return 0;
}