#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
map<char,char>mp;
map<char ,int>ara;
int r , p , s , vis[200] , n;
char  ans[200];

int main()
{
    fastRead;
    mp['R'] = 'P';
    mp['P'] = 'S';
    mp['S'] = 'R';
    
    int t;
    cin>>t;
    while(t--) {
        
        ara.clear();
        cin>>n;
        cin>>r>>p>>s;
        
        ara['R'] = r;
        ara['P'] = p;
        ara['S'] = s;
        
        string str;
        cin>>str;
        memset(vis , 0 , sizeof vis);
        for(int i =0 ;i < n ; i++) ans[i] = '*';
        int cnt = 0;
        
        for(int i =0 ; i <n ; i++  ) {
            
            char ch = str[i];
            char tgt = mp[ch];
            
            
            if(ara[tgt] > 0 ) {
                ans[i] = tgt;
                vis[i] = 1;
                cnt++;
                ara[tgt]--;
            }
        }
        if(cnt *2 < n) {
            cout<<"NO\n";
            continue;
        }
        
        cout<<"YES\n";
        for(int i =0 ; i < n ; i++ ) {
            
            if(vis[i]) cout<<ans[i];
            else {
                
                if(ara['R'] > 0) {
                    cout<<'R';
                    ara['R']--;
                }
                else if(ara['P'] > 0) {
                    cout<<'P';
                    ara['P']--;
                }
                else if(ara['S'] > 0 ) {
                    cout<<'S';
                    ara['S']--;
                }
                else assert(0);
            }
        }
        cout<<'\n';
        
    }
    return 0;
    
}