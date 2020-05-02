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
        vector<int>vec;
        ll tot = 0;
        
        for(int i = 0 ; tot < n ; i++ ) {
            if( (1LL<<i) + tot > n ) {
                vec.push_back(n - tot);
                break;
            }
            else {
                vec.push_back(1LL<<i);
                tot += 1LL<<i;
            }
        }
        
        sort(vec.begin() , vec.end());
        
        cout<<vec.size()-1<<'\n';
        for(int i =1 ; i < vec.size() ; i++ ) cout<<vec[i] - vec[i-1]<<" ";
        cout<<'\n';
    }
    return 0;
    
}