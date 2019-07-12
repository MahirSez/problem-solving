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
vector<pii>vec;
int main()
{
    cin>>n;
    int rem0 = n%4;
    if( rem0 == 1) cout<<0<<" "<<'A'<<endl;
    else if( rem0 ==2) cout<<1<<" "<<'B'<<endl;
    else if( rem0 == 3) cout<<2<<" "<<'A'<<endl;
    else cout<<1<<" "<<'A'<<endl;
    return 0;
    
}