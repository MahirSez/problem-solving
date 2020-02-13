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

int last[MAX] , ara[MAX];
int main()
{
    fastRead;
    int n;
    cin>>n;
    for(int i =1 ; i <=n ; i++ ) cin>>ara[i];
    double ans = 0;
    
    
    for(int i  =1 ;  i<= n ; i++) {
        
        double tmp = 1.00 *(i - last[ ara[i] ]) * (n - i + 1) *2 - 1;
        ans += tmp;
        
        last[ara[i]] = i;
    }
    ans /= 1.0* n * n;
    
    cout<<setprecision(6)<<fixed<<ans<<'\n';
    return 0;
    
}