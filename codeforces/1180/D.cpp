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
int n , m;

void solve(int r1 , int r2 ) {

    
    if( r1 > r2) return;
    
    if( r1 == r2 ) {
        
        for(int c1 = 1 , c2 = m ; c1 <=c2 ; c1++ , c2--) {
            
            if( c1 == c2) {
                cout<<r1<<" "<<c1<<'\n';
            }
            else {
                cout<<r1<<" "<<c1<<'\n';
                cout<<r1<<" "<<c2<<'\n';
            }
        }
        return ;
    }
    
    for(int c1 =1 , c2 = m; c1 <= m ; c1++ , c2-- ) {
        
        cout<<r1<<" "<<c1<<'\n';
        cout<<r2<<" "<<c2<<'\n';
    }
    solve(r1+1 , r2-1);
    
}

int main()
{
    cin>>n>>m;
    
    solve(1 , n);
    return 0;
}