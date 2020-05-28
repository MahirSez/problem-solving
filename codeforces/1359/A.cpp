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
        int n , m , k;
        cin>>n>>m>>k;
        
        int per = n/k;
        int x = min(per , m);
        m -= x;
        int y = m/(k-1);
        
        if( m%(k-1)) y ++;
        
        cout<<x-y<<'\n';
    }
    return 0;
    
}