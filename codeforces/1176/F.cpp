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
int t , n;
vector<ll>ara[4][MAX];
ll dp[MAX][15];
ll ans;

ll solve(int id , int koyta) {
    
    
    
    if( id ==t ) return 0;
    
    ll &ret = dp[id][koyta] ;
    if(ret != -1) return ret;
    
    
    ret = max(ret , solve(id+1 , koyta) );
    
    if( ara[3][id].size() > 0) {
        ret = max(ret , solve(id+1 , (koyta+1)%10 ) + (ara[3][id][0] + ( (koyta>=9)? ara[3][id][0] : 0   )  ) );
    }
    
    if(ara[2][id].size() > 0 && ara[1][id].size()> 0 ) {
        ret = max(ret , solve(id+1 , (koyta+2)%10 ) + (ara[2][id][0] + ara[1][id][0] + ( (koyta >= 8 )? max(ara[2][id][0] , ara[1][id][0]) : 0) ) );
    }
    
    if(ara[1][id].size() > 2 ) {
        ret = max(ret , solve(id+1 , (koyta+3)%10 ) + (ara[1][id][0] + ara[1][id][1] +  ara[1][id][2] + ( (koyta>=7)? ara[1][id][0] : 0  ) ) );
    }
    
    if(ara[2][id].size() > 0 ) {
        ret = max(ret , solve(id+1 , (koyta+1)%10 ) + (ara[2][id][0] + ( (koyta>=9)? ara[2][id][0] : 0  ) ) );
    }
    if(ara[1][id].size() > 0 ) {
        ret = max(ret , solve(id+1 , (koyta+1)%10 ) + (ara[1][id][0] + ( (koyta>=9)? ara[1][id][0] : 0 ) ) );
    }
    
    if(ara[1][id].size() > 1 ) {
        ret = max(ret , solve(id+1 , (koyta+2)%10 ) + (ara[1][id][0] + ara[1][id][1] + ( (koyta>=8)? ara[1][id][0] : 0  ) ) );
    }
    
    
    
    return ret;
    
}

int main()
{
    fastRead;
    cin>>t;
    
    for(int i =0 ; i < t ; i++ ) {
        
        int n;
        cin>>n;
        for(int j =0 ; j < n ; j++ ) {
            int type;
            ll tmp;
        
            cin>>type>>tmp;
            ara[type][i].push_back(tmp);
        }
        
        sort(ara[1][i].rbegin() , ara[1][i].rend());
        sort(ara[2][i].rbegin() , ara[2][i].rend());
        sort(ara[3][i].rbegin() , ara[3][i].rend());
    }
                
        
//    for(int j =1 ;j <=3 ; j++ ) {        
//        for(int i =0 ; i < t ; i++ ) {
//        
//            for(auto x : ara[j][i]) {
//                cout<<x<<" ";
//            }
//        }
//        cout<<endl;
//    }
//    cout<<endl<<endl;
    memset(dp , -1 , sizeof dp);
    cout<<solve(0 , 0)<<'\n';
    return 0;
}