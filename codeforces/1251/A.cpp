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
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int ara[30];
        memset(ara , 0  ,sizeof ara);
        
        string str;
        cin>>str;
        str += '*';
        
        int n = str.size();
        int cnt = 1;
        
        for(int i =0 ; i <n-1;i++ ) {
            
            if(str[i] != str[i+1]) {
                
                if(cnt &1) ara[str[i]-'a'] =1;
                cnt = 1;
            }
            else cnt++;
        }
        for(int i =0 ; i < 26 ;i++ ) {
            if(ara[i]) cout<<char(i + 'a');
        }
        cout<<'\n';
    }
    return 0;
}