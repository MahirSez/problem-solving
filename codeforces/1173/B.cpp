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
    int sz = -1;
    
    for(int i =0 ; ; i++ ) {
        
        if( 1 + 2*i >= n) {
            sz = i+1;
            break;
        }
    }
    
    cout<<sz<<endl;
    int mid = n/2;
    
    for(int i = 1 ; i <= mid ; i++ ) {
        cout<<1<<" "<<i<<'\n';
    }
    int j = sz ;
    for(int i = mid + 1 , j = 1; i <= n ; i++ , j++ ) {
        cout<<sz<<" "<<j<<'\n';
    }
    return 0;
}