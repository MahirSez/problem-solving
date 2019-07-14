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
int q;
int  n, m  ;

int main()
{
    fastRead;
    cin>>q;
    while( q-- ) {
        int n , m;
        cin>>n>>m;
        
        vector<int>roSum(n) , colSum(m);
        
        
        vector< vector<int> > ara;
        
        for(int i =0 ; i < n ;i++  ) {
            
            string str;
            cin>>str;
            
            vector<int>tmp;
            for(int j = 0 ; j < m ; j++ ) {
                if( str[j] =='*') tmp.push_back(1);
                else tmp.push_back(0);
            }
            
            ara.push_back(tmp);
        }
        
        for(int i =0 ; i < n ; i++ ) {
            int tot = 0;
            
            for(int j =0 ; j < m ; j++ ) {
                if(ara[i][j] == 0) tot++;
            }
            
            roSum[i] = tot;
        }
        
        for(int j =0 ; j < m ; j++ ) {
            
            int tot = 0;
            for(int i = 0 ; i < n ;i++ ) {
                if(ara[i][j]==0) tot++;
            }
            colSum[j] = tot;
        }
        
        int ans = INF;
        for(int i = 0 ; i < n ; i++ ) {
            for(int j =0 ; j < m ; j++ ) {
                int can = roSum[i] + colSum[j];
                if(ara[i][j]==0) can--;
                ans = min(ans , can);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;

}