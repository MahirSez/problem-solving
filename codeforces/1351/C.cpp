#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define ppp         pair<pii,pii>
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
        string s;
        cin>>s;
        map<ppp , int>mp;
        int lx = 0 , ly = 0;
        int ans = 0;
        
        for(auto xx : s ) {
                
            int x = lx , y = ly;
            if(xx == 'N') x = lx+1;
            else if(xx == 'S') x = lx - 1;
            else if(xx == 'E') y = ly + 1;
            else if(xx == 'W') y = ly - 1;
            else assert(0);
            
                
            if(mp[{{x,y} , {lx,ly}}]) ans++;
            else {
                mp[{{x,y} , {lx , ly}}] = 1;
                mp[{{lx,ly} , {x , y}}] = 1;
                ans +=5;
            }
            
            lx = x;
            ly = y;
        }
        cout<<ans<<'\n';
    }
    return 0;
}