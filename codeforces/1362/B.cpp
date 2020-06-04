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
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int>vec(n) , rec(1100);
        for(int i =0 ; i < n ; i++) {
            cin>>vec[i];
            rec[vec[i]]++;
        }
        
        int ret = -1;
        
        for(int k =1 ; k < 1024 ; k++ ) {
            
            vector<int>tmp = rec;
            bool ok = 1;
            
            for(int i =0 ; i < 1024 ; i++ ) {
                
                if(tmp[i] == 0) continue;
                if(tmp[i^k] == 0) {
                    ok = 0;
                    break;
                }
                
                tmp[i^k]--;
                tmp[i]--;
            }
            if(ok) {
                ret = k;
                break;
            }
        }
        cout<<ret<<'\n';
    }
    return 0;
}