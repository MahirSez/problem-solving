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
int n ;
int ara[MAX] , pos[MAX];
vector<pii>ans;


void Change(int id1 , int id2 ) {

    ans.push_back({id1 , id2});
    int num1 = ara[id1];
    int num2 = ara[id2];
    
    swap(ara[id1] , ara[id2]);
    swap(pos[num1] , pos[num2]);
}

int main()
{
    fastRead;
    cin>>n;
    for(int i = 1 ; i <= n ; i++ ) cin>>ara[i] , pos[ara[i]] = i;
    
    for(int i = n/2; i>=1; i--) {
        
        if( pos[i] == i ) continue;
        if( 2*abs(pos[i] - i)>= n ) {
            
            
            Change(i , pos[i]);
            
            continue;
        }
        if( 2*(n - pos[i]) >= n) {
            Change(pos[i] , n);
            Change(pos[i] , i);
            continue;
        }
        
        Change(pos[i] , 1);
        Change(pos[i] , n);
        Change(pos[i] , i);
        
        
    }
    for(int i = n/2 + 1 ; i <= n ; i++ ) {
            
        if( pos[i] ==i ) continue;
        
        int koi = pos[i];
        Change(pos[i] , 1);
        Change(pos[i] , i);
        Change(koi , 1);
        
    }
    
    assert(ans.size() <= 5*n);
    
    
    cout<<ans.size()<<'\n';
    for(auto x: ans) {
        cout<<x.uu<<" "<<x.vv<<'\n';
    }
    return 0;
}

