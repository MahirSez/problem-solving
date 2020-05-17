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
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        n*=2;
        double ans = tan(acos(-1)/n);
        ans = 1/ans;
        cout<<setprecision(10)<<fixed<<ans<<'\n';
    }
    return 0;
    
}