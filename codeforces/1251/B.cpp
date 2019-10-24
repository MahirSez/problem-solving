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
        
        int n;
        cin>>n;
        vector<int>odd , ev;
        int one = 0 , zero =0;
        
        for(int i =0 ; i < n ; i++ ) {
            string str;
            cin>>str;
            int tmp = str.size();
            if(tmp &1) odd.push_back(tmp);
            else ev.push_back(tmp);
            
            for(auto x : str) {
                if(x == '1') one++;
                else zero++;
            }
        }
        int ans = 0;
        
        for(auto x : ev) {
            
            int tgt = x;
            
            bool ok = true;
            while(tgt > 0) {
                
                if(one > 1) {
                    tgt -=2;
                    one-=2;
                }
                else if(zero >1) {
                    tgt -=2;
                    zero -=2;
                }
                else {
                    ok = false;
                    break;
                }
            }
            if(ok) ans++;
        }
        
        for(auto x : odd) {
            int tgt = x;
            
            bool ok = true;
            tgt--;
            
            while(tgt > 0) {
                
                if(one > 1) {
                    tgt -=2;
                    one-=2;
                }
                else if(zero >1) {
                    tgt -=2;
                    zero -=2;
                }
                else {
                    ok = false;
                    break;
                }
            }
            
            if(one > 0 ) one--;
            else if(zero > 0) zero--;
            else ok = false;
            
            if(ok) ans++;
        }
              
        cout<<ans<<'\n';
    }
    return  0;
}