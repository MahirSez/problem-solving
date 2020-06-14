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
int mark[MAX] , ara[MAX];

int main()
{
    fastRead;
    
    int n;
    cin>>n;
    
    for(int i =0 ; i < n ; i++ ) {
        int tmp ;
        cin>>tmp;
        ara[tmp]++;
    }
    
    if(ara[1]) {
        if(ara[1] ==1 ) cout<<1<<'\n';
        else cout<<0<<'\n';
        return 0;
    }
    int ans = 0;
    for(int i =2 ; i < MAX ; i++ ) {
        if(ara[i] ==0 || mark[i] ) continue;
        
        for(int j = i*2 ; j < MAX ; j +=i ) mark[j] = 1;
        
        if(ara[i] == 1) ans++;
    }
    
    cout<<ans<<'\n';
    return 0;
}