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
int n , hand[MAX] , st[MAX] , aux[MAX] ;
int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i <= n ; i++ ) {
        int tmp;
        cin>>tmp;
        hand[tmp] = 1;
    }
    int pos = -1;
    for(int i =1 ; i <= n ; i++ ) {
        cin>>st[i];
        if( st[i] == 1) pos = i;
    }
    
    for(int i = 1 ; i  <= n ; i++) {
            
        if( st[i]==0) continue;
        int tmp = i - st[i] +1;
        if( tmp >=1) aux[tmp] = 1;
    }
    int last = 0;
    
    for(int i =1 ; i <= n ; i++ ) {
        if(aux[i] ) last = i;
    }
    
    int ans1 = last+ n;
    
    bool ok = true;
    for(int i = pos + 1;  i  <= n ; i++ ) {
        if( st[i] - st[i-1] != 1) {
            ok = false;
        }
    }
    
    
    if( !ok ) {
        cout<<ans1<<'\n';
        return 0;
    }
    
    int head = 1;
    
    int tmp = st[n];
    int ans2 = 0;
    
    for(int i = tmp +1; i <=n ; i++ ) {
        
        if( hand[i] ==0  ) {
            ans2 = INF;
            break;
        }
        
        hand[st[head]] = 1;
        head++;
        ans2++;
    }
    
    cout<<min(ans1 , ans2)<<'\n';
    
    return 0;
    
}