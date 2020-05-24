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

bool check(string &s , vector<string>&vec) {
    
    bool ok = 1;
    for(auto x :  vec) {
        
        int cnt = 0;
        for(int i =0 ; i < s.size() ; i++ ) {
            if(x[i] != s[i]) cnt++;
        }
        if(cnt > 1) return 0;
    }
    return 1;
}


int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n , m;
        cin>>n>>m;
        vector<string>vec(n);
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        
        string ans = "-1";
        
        for(int i =0 ; i < n ; i++ ) {
            
            for(int j =0 ; j < m ; j++ ) {
                
                string tgt = vec[i];
                for(int k =0 ; k < 26 ; k++ ) {
                    
                    tgt[j] = char(k + 'a');
                    bool ret = check(tgt , vec);
                    if(ret) ans = tgt;
                    
                }
            }
        }
        
        cout<<ans<<'\n';
    }
    return 0;
}
