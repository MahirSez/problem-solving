#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         100005  
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , x;
vector<int>ans;

int main()
{
    cin>>n>>x;
    int msb = -1;
    for(int i =0 ; i < 31 ; i++ ) {
        if( x & (1<<i) ) msb = i;
    }
    int lastBit=-1;
    
//    if( x ==1 ) ans.push_back(2) , lastBit = 1;
//    else ans.push_back(1) , lastBit = 0;
    
    
    while(lastBit +1< n) {
        
        lastBit++;
        if( lastBit == msb) {
            
            continue;
        }
        ans.push_back((1<<lastBit) );
        int nn = ans.size();
        
        for(int i =0 ; i < nn -1 ; i++ ) {
            ans.push_back(ans[i]);
        }
    }
    cout<<ans.size()<<'\n';
    for(auto x: ans) {
        cout<<x<<" ";
    }
    cout<<'\n';
    return 0;
}