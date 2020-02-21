#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pdd         pair<double , double>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

int ara[MAX] ;

int main()
{
    fastRead;
    int n;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i] ;
    
    stack<pdd>st;
    
    for(int i = n-1 ; i>= 0 ; i-- ) {
        
        double val = ara[i];
        double cnt = 1;
        
        while(!st.empty() && val >= st.top().uu ) {
            
            double topavg = st.top().uu;
            double topcnt = st.top().vv;
            
            st.pop();
            
            val = (val * cnt + topavg*topcnt)/(cnt + topcnt);
            cnt += topcnt;
        }
        st.push({val , cnt});
    }
    
    while(!st.empty() ) {
        
        double val = st.top().uu;
        int cnt = st.top().vv;
        st.pop();
        
        while(cnt--) cout<<setprecision(12)<<fixed<<val<<'\n';
    }
    return 0;
    
}