#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define ppi         pair<pii,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         100004
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int  n ,  a , x , b , y;
int main()
{
    cin>>n>>a>>x>>b>>y;

    while(1) {

        if( a == b) {
            cout<<"YES"<<endl;
            return 0;
        }
        if(a == x || b == y) break;

        a++;
        b--;
        if( a == n+1) a = 1;
        if( b ==0) b = n;

    }
    cout<<"NO"<<endl;
    return 0;
}
