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
        
        deque<int>dq;
        int n;
        cin>>n;
        for(int i =0 ; i < n ; i++ ) {
            int tmp;
            cin>>tmp;
            dq.push_back(tmp);
        }
        
        int alice = 1;
        
        int atot = 0 , btot = 0 , cnt = 0;
        int alast = 0 , blast = 0;
        
        while(!dq.empty()) {
            
            if(alice) {
                alast = 0;
                while(!dq.empty() && alast <= blast ) {
                    
                    alast += dq.front();
                    dq.pop_front();
                }
                atot +=alast;
                alice ^=1;
            }
            else {
                blast = 0;
                while(!dq.empty() && blast <= alast ) {
                    
                    blast += dq.back();
                    dq.pop_back();
                }
                btot += blast;
                alice ^=1;
            }
            cnt++;
        }
        cout<<cnt<<" "<<atot<<" "<<btot<<'\n';
        
    }
    return 0;
}