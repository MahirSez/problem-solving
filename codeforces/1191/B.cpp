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
string s[3] ;
vector<int>vec[3];
int main()
{
    cin>>s[0]>>s[1]>>s[2];
    
    if(s[0] ==s[1] && s[1] == s[2]){
        cout<<0<<endl;
        return 0;
    }
    
    for(int i =0 ; i < 3 ; i++ ) {
        if( s[i][1] == 's') vec[0].push_back(s[i][0]-'0');
        if( s[i][1] == 'm') vec[1].push_back(s[i][0]-'0');
        if( s[i][1] == 'p') vec[2].push_back(s[i][0]-'0');
    }
    for(int i =0 ; i <3 ; i++ ) {
        sort(vec[i].begin() , vec[i].end() ) ;
        
    }
    int ans = 10;
    
    for(int i =0 ; i < 3 ; i++ ) {
        if(vec[i].size() ==0 ) ans = min(ans , 3);
        
        else if( vec[i].size() == 1) ans = min(ans , 2);
        
        else if( vec[i].size() == 2 ) {
            
            int dst = vec[i][1] - vec[i][0];
            if( dst <=2 ) ans = min(ans , 1);
            else ans = min(ans , 2);
        }
        
        else {
            int dst1 = vec[i][1] - vec[i][0];
            int dst2 = vec[i][2] - vec[i][1];
            int dst3 = vec[i][2] - vec[i][0];
            
            if(dst1 == 1 && dst2 == 1)  ans = min(ans , 0);
            
            else if( dst1 <= 2 || dst2 <= 2  ) ans = min(ans , 1);
            else ans = min(ans , 2) ;
        }
    }
    cout<<ans<<endl;
    return 0;
}