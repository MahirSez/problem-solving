#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e5 + 6;
int ara[30][MAX] , ase[30];
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        string s , t;
        cin>>s>>t;
        memset(ara , -1 , sizeof ara);
        memset(ase , -1 , sizeof ase);
        
        int n1 = s.size();
        int n2 = t.size();
        
        for(int i = n1-1 ; i>=0 ; i--) {
            
            for(int j = 0 ; j < 30 ; j++ ) ara[j][i] = ara[j][i+1];
            
            int id = s[i] - 'a';
            ase[id] =1;
            ara[ id ][i] = i;
            
        }
        bool ok = 1;
        for(auto x : t) {
            if(ase[x-'a'] == -1 ) ok=0;
        }
        
        if(!ok) {
            cout<<-1<<'\n';
            continue;
        }
        
        int cnt = 1;
        
        int now = 0;
        
        for(auto x : t) {
            int tgt = x-'a';
            
            if(ara[tgt][now] == -1) {
                cnt++;
                now = 0;
            }
            
            now = ara[tgt][now] +1;
        }
        
        cout<<cnt<<'\n';
        
        
    }
    return 0;
    
}