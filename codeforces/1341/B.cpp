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
        
        int n , k;
        cin>>n>>k;
        vector<int>vec(n+1) , sum(n+1);
        
        for(int i =1;  i<=n ; i++ ) cin>>vec[i];
        
        for(int i = 2 ;i < n ; i++ ) {
            if(vec[i] > vec[i-1] && vec[i] > vec[i+1]) sum[i] = 1;
        }
        
        for(int i =1 ; i <=n ; i++ ) sum[i] += sum[i-1];
        
        int mxPart = -1 , l = -1;
        
        for(int i = 1 ; i + k-1 <=n ; i++ ) {
            
            int frm = i+1;
            int to = i + k-2;
            
            int tmp = sum[to] - sum[frm-1] + 1;
            
            if(tmp > mxPart) {
                mxPart = tmp;
                l = i;
            }
        }
        assert(mxPart != -1);
        cout<<mxPart<<" "<<l<<'\n';
    }
    return 0;
}