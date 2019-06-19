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
int n , m , ara[MAX] , sum;

int get(int tot , int val)  {
    
    int lo = 0 , hi = ara[val];
    int ans = -1;
//    cout<<sum<<" "<<tot<<" "<<val<<" "<<ara[val]<<endl;
    
    while( lo <= hi ) {
        
        int mid = (lo+hi)>>1;
        if( tot - mid * val <= m) {
            ans = mid;
            hi = mid-1;
        }
        else {
            
            lo = mid+1;
        }
    }
//    cout<<ans<<endl;
    
    return ans;
    
}

int solve() {
        
    

    int tot = sum;
    int cnt = 0;
    if( tot <=m) return 0;
    
    for(int i = 100 ; i >=1 ; i-- ) {
        if( ara[i] ==0 ) continue;
        
        if( tot - ara[i]* i <= m) {
//            cout<<endl<<i<<endl;
            cnt += get(tot , i);
            break;
        }
        else {
            cnt += ara[i];
            tot -= ara[i]*i;
        }
    }
    return cnt;
    
}


int main()
{
    fastRead;
    cin>>n>>m;
    
    for(int i =1 ; i <= n ; i++) {
        int tmp;
        cin>>tmp;
        
        sum += tmp;
        
            
        cout<<solve()<<" ";
            
        ara[tmp]++;
    }
    cout<<'\n';
    return 0;
}