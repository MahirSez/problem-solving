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
int x , y,z;
int main()
{
    cin>>x>>y>>z;
    bool win = false;
    if( x > y) win = true;
    if( x < y) swap(x,y);
    
    if( x > y && y + z >= x ) {
        cout<<"?"<<endl;
        return 0;
    }
    if( x ==y && y + z > x) {
        cout<<"?"<<endl;
        return 0;
    }
    if( x== y ) {
        cout<<0<<endl;
    }
    else if( win) {
        cout<<"+\n";
    }
    else cout<<"-\n";
    
    return 0;
}