#include<bits/stdc++.h>
#define uu first
#define vv second
#define pii pair<int,int>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    
    stack<pii>st;
    int ans = 0;
    
    
    for(int i =0 ; i < n ; i++ ) {
        
        int tmp;
        cin>>tmp;
        
        if( st.empty()) {
            st.push({0,tmp});
            continue;
        }
        
        if( tmp <=st.top().vv ) {
            st.push({1, tmp});
            ans = max(ans , 1);
        }
        
        else {
            int now = -1;
            
            
            while(!st.empty() && tmp > st.top().vv ) {
                now = max(now , st.top().uu+1 );
                st.pop();
            }
            
            if( st.empty() ) now = 0;
            
            ans = max(ans , now);
            
            st.push({now , tmp});
        }
    }
    cout<<ans<<'\n';
    return 0;
    
}