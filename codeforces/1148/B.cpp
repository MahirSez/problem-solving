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
int n , m , ta , tb , k;
vector<int>a , b;
int main()
{
    fastRead;
    cin>>n>>m>>ta>>tb>>k;
    for(int i =0 ; i < n ; i++ ) {
        int val;
        cin>>val;
        a.push_back(val);
    }
    for(int i =0 ; i < m ; i++ ) {
        int val;
        cin>>val;
        b.push_back(val);
    }
    int tmp = k;
    
    if( k >= n || k>= m ) {
        cout<<-1<<endl;
        return 0;
    }
    ll ans = 0;
    
    for(int i = 0 ; i < min( k +1, n ) ; i++) {
        
        int val = a[i] + ta;
        
        int id = lower_bound(b.begin() , b.end() , val) - b.begin();
        
        if( id + tmp >= m)  {
            cout<<-1<<'\n';
            return 0;
        }
        ans = max(ans , 1LL*b[id+tmp] + tb);
        tmp--;
    }
    
    cout<<ans<<'\n';
    return 0;
}