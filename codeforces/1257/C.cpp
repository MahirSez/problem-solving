#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 2e5 + 5;
vector<int>vec[MAX];
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n ;
        cin>>n;
        for(int i=1;  i <=n ; i++ ) vec[i].clear();
        
        for(int i =0 ; i < n ; i++ ) {
            int tmp;
            cin>>tmp;
            vec[tmp].push_back(i);
        }
        int ans = INF;
        
        for(int i =1 ; i <=n ; i++ ) {
            
//            cout<<i<<" "<<vec[i].size()<<'\n';
            if(vec[i].size() == 0 ) continue;
            
            for(int j = 0 ; j < vec[i].size()-1 ;j++  ) {
                
                ans = min(ans , vec[i][j+1] - vec[i][j]+1);
            }
        }
        
        if(ans == INF) ans = -1;
        cout<<ans<<'\n';
    }
    return 0;
}