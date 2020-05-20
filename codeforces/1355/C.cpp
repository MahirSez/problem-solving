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

ll sum[MAX];

int main()
{
    fastRead;
    int a , b , c , d;
    cin>>a>>b>>c>>d;
    
    for(int i =a ; i <=b ; i++ ) {
        sum[b+i-1]--;
        sum[c+i]++;
    }
    for(int i = MAX-2 ; i >=0 ;i--) {
        sum[i] += sum[i+1];
    }
    
    assert(sum[0] == 0 ) ;
    
    ll tot = 0;
    ll ans = 0;
    
    for(int i = MAX-1 ; i >= c ; i--) {
        
        if(i <=d ) ans += tot;
        tot += sum[i];
    }
    cout<<ans<<'\n';
    
    return 0;
    
}