#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
string f = "Ayush";
string s = "Ashish";
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n, x;
        cin>>n>>x;
        vector<int>deg(n+1);
        for(int i =1 ; i < n ; i++) {
            int u , v;
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
        }
        
        if(deg[x] <=1) {
            cout<<f<<'\n';
            continue;
        }
        
        if(n&1) cout<<s<<'\n';
        else cout<<f<<'\n';
    }
    return 0;
    
}