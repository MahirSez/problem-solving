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
#define MAX         2000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string ss ;
int ara[MAX] , str[20][20][20];
ll  rec[15][MAX];


int solve(int tgt , int n1 , int n2) {


    int ret = INF;

    for(int i = 0 ; i <= 10 ; i++ ) {
        
        for(int j =0 ; j<= 10 ; j++ ) {
            
            if( i == 0 && j ==0 )  continue;
            
            if( (n1*i + n2*j)%10 == tgt ) ret = min(ret , i+j);
        }
    }
    
//    cout<<tgt<<" "<<n1<<" "<<n2<<" "<<ret<<endl;
    if( ret == INF) return INF;
    return ret-1;

}

int main()
{
    fastRead;
    cin>>ss;
    
    
    for(int i =0 ; i < ss.size() ; i++ ) {
        ara[i] = ss[i] - '0';
    }
    
    for(int i =0 ; i <= 9 ; i++ ) {
        
        for(int j =0 ; j <=9 ; j++ ) {
            
            for(int k =0 ; k <= 9 ; k++ ) {
                
                
                str[i][j][k] = solve(i , j , k);
                
            }
        }
    }
    
    for(int i =0 ; i <= 9 ; i++ ) {
        
        for(int j = 0 ; j <= 9 ; j++ ) {
            
            
            
            ll ans = 0;
            for(int k = 0 ; k < ss.size()-1 ; k++ ) {
                
                
                int gap = ara[k+1] - ara[k];
                if(gap < 0 ) gap +=10;
                ans += str[gap][i][j];
                
            }
            
            
            if( ans  < INF) cout<<ans<<" ";
            else cout<<-1<<" ";
        }
        cout<<'\n';
    }
    return 0;
}