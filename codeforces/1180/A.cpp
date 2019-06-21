#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n;
int main()
{
    cin>>n;
    if( n == 1)  {
        cout<<1<<endl;
        return 0;
    }
    
    int to = 2*n -1;
    int ans = 0;
    for(int i =1 ; i< to ; i+=2 ) {
        ans += i*2;
    }
    ans += to;
    cout<<ans<<endl;
    return 0;
}