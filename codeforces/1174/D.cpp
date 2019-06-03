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
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , x , pre[MAX] , taken[MAX];
vector<int>ans;
int main()
{
    cin>>n>>x;
    taken[x] = 1;
    
    
    for(int i = 1; i < (1<<n) ; i++ ) {
            
        if( taken[i] ) continue;
        ans.push_back(i);
        taken[x^i] =1;
    }
    int prev = 0;
    
    cout<<ans.size()<<endl;
    for(int i =0 ; i < ans.size() ;i++) {
        cout<<(ans[i]^prev)<<" ";
        prev = ans[i];
    }
    cout<<endl;
    return 0;
}