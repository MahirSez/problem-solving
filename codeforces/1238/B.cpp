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
        
        int n ;
        ll r;
        cin>>n>>r;
        vector<ll>vec(n);
        for(int i =0 ; i < n ; i++) cin>>vec[i];
        
        sort(vec.begin() , vec.end());
        
        
        ll cnt = 0;
        
        for(int i = n-1 ; i >= 0 ; i--) {
            
            if(i < n-1 && vec[i] == vec[i+1] ) continue;
            
            if(vec[i] - cnt* r > 0 ) {
                cnt++;
            }
            
        }
        cout<<cnt<<'\n';
    }
    return 0;
}