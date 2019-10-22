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
int to[MAX] , n , ans[MAX];
int main()
{
    fastRead;
    int q;
    cin>>q;
    while(q--) {
        cin>>n;
        for(int i =1 ; i<=n ; i++ ) cin>>to[i];
        for(int i =1 ; i<=n ; i++ ) ans[i] = -1;
        
        for(int i =1 ; i<=n ; i++ ) {
            
            if(ans[i]!= -1) continue;
            
            int cnt = 0 , now = i;
            
            while(1) {
                
                cnt++;
                if(to[now] == i) break;
                now = to[now];
            }
            now = i;
            
            while(1) {
                ans[now] = cnt;
                if(to[now] == i) break;
                now = to[now];
            }
        }
        for(int i =1 ; i<=n ; i++ ) cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
}