#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pip         pair<int, pii >
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int ara[MAX] , call[MAX] , ans1[MAX] , bit[MAX];
int n , m , ans2[MAX] , rt , fre[MAX];
bool taken[MAX];
vector<int>rec[MAX];

vector<pip>q;
int ans = 0;


void update(int x , int val) {
//    cout<<x<<" "<<val<<'\n';
    for( ;  x<=n ; x += x&-x ) {
        bit[x] += val;
    }
    
}

int query(int x) {
    int sum = 0;
    for( ; x > 0 ; x -= x&-x) sum += bit[x];
    
    return sum;
}

bool comp(pip &p1 , pip &p2) {
    
    if( p1.vv.uu/rt == p2.vv.uu/rt ) return p1.vv.vv < p2.vv.vv;
    return p1.vv.uu/rt < p2.vv.uu/rt ;
}
void Add(int pos) {
    fre[call[pos]]++;
    if(fre[call[pos]] == 1) ans++;
}

void Remove(int pos) {
    fre[call[pos]]--;
    if(fre[call[pos]] == 0 ) ans--;
}


void solve() {
    
    
    
    sort(q.begin() , q.end() , comp) ;
    
    // cout<<rt<<'\n';
    // for(auto x : q) cout<<x.uu<<" -- "<<x.vv.uu<<" "<<x.vv.vv<<'\n';
    
    int l = 1 , r = 0;
    
    for(auto x : q) {
        
        int frm = x.vv.uu;
        int to = x.vv.vv;
        
        int id = x.uu;
        
        
        while(l  < frm) Remove(l++);
        while(l > frm) Add(--l);
        
        while(r < to ) Add(++r);
        while(r > to ) Remove(r--);

        // cout<<l<<" "<<r<<" "<<ans<<'\n';
        // for(int i = 0 ; i <= n ; i++ ) cout<<fre[i]<<" ";
        // cout<<'\n';
        
        ans2[id] = max(ans2[id] , ans+1);
    }
}

int main()
{
    fastRead;
    cin>>n>>m;
    rt = sqrt(n);
    
    for(int i = 1 ; i <= n ; i++ ) ara[i] = i , ans1[i] = ans2[i] = i ;
    for(int i = 1;  i <=m ; i++ ) cin>>call[i] , ans1[call[i]] = 1;
    
    
    
    for(int i =1 ; i <= m ; i++ ) {
        
        // cout<<call[i]<<" ->";
        if(taken[call[i]] == 0 ) {
            taken[call[i]] = 1;
            
            // cout<<query(n)<<" "<<query(call[i]);
            
            ans2[call[i]]  = max(ans2[call[i]] , call[i] + query(n) - query(call[i]) );
            
            update(call[i] , 1);
        }
        // cout<<'\n';
        
        rec[call[i]].push_back(i);
    }

    for(int i= 1 ;i <=n ; i++ ) {
        if(taken[i]) continue;

        // cout<<" "<<i<<" "<<query(n)<<" "<<query(i)<<'\n';

        ans2[i] = max(ans2[i] , i + query(n) - query(i));
    }

    for(int i =1; i <= n ; i++ ) rec[i].push_back(m+1);

    
    for(int i =1 ; i <=n ; i++ ) {
            
        
        if(rec[i].size() ==1 ) continue;
        for(int j = 0 ; j < rec[i].size() -1 ; j++) {
            
            
            int frm = rec[i][j];
            int to = rec[i][j+1];
            if(frm + 1 == to) continue;
            q.push_back( { i , {frm+1 , to-1} } );

            // cout<<i<<" "<<frm<<" "<<to<<'\n';

        }
    }
    

    
    solve();
    
    for(int i =1 ; i <=n ; i++ ) cout<<ans1[i]<<" "<<ans2[i]<<'\n';
    return 0;
    
}