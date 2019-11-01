#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define plp         pair<ll , pii>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e4 + 4;
int n , x[MAX] , y[MAX] , c[MAX] , w[MAX];
vector<plp>vec;

ll ans;
int cnt  ,par[MAX], mark[MAX], k[MAX];
vector<pii>sol;

int boss(int x) {
    
    return (par[x] == x ) ? par[x] : (par[x] = boss(par[x]) );
}

void mst() {
    
    sort(vec.begin() , vec.end());
    
    for(int i =1 ; i <= n ; i++ ) par[i] = i , mark[i] = 1;
    for(auto x : vec) {
        
        ll w = x.uu;
        int u = x.vv.uu;
        int v = x.vv.vv;
        
        int parU = boss(u);
        int parV = boss(v);
        
        if(parU == parV) continue;
        
        if(c[parU] < c[parV]) {
            swap(u , v);
            swap(parU , parV);        
        }

        if(w<=c[parU] ) {
            
            cnt--;
            ans= ans - c[parU] + w;
            par[parU] = parV;
            sol.push_back({u , v});
            mark[parU] = 0;
        }
        else  {
            par[parV] = parV;
        }
    }
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i <=n ; i++ ) cin>>x[i]>>y[i];
    
    for(int i =1 ; i <=n ; i++ ) {
        cin>>c[i];
        ans += c[i];
    }
    
    for(int i =1 ; i <=n ; i++ ) cin>>k[i];
    cnt = n;
    
    for(int i =1 ; i <=n ; i++ ) {
        for(int j = i+1 ; j <=n ; j++ ) {
            
            ll dist = abs(x[i] -x[j]) + abs(y[i] - y[j]);
            
            ll cst = dist * (k[i] + k[j]);
            vec.push_back({cst , {i , j} });
        }
    }
    
    mst();
    cout<<ans<<'\n';
    cout<<cnt<<'\n';
    int tmp = 0;
    for(int i =1 ; i <=n ; i++ ) {
        if(mark[i]) {
            cout<<i<<" ";
            tmp++;
        }
    }
    
    assert(tmp == cnt);
    cout<<'\n';
    cout<<sol.size()<<'\n';
    for(auto x : sol) cout<<x.uu<<" "<<x.vv<<'\n';
    return 0;
    
}