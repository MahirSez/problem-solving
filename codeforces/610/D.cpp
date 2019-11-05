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

int n  , frmx[MAX] , frmy[MAX] , tox[MAX] , toy[MAX];

map<int,int>x , y ;

int xx[MAX] , yy[MAX] , tmpx[MAX];


void compress() {
    for(int i =0 ; i < n ; i++ ) {
        x[frmx[i]]= 1;
        x[tox[i]]= 1;
        x[tox[i]+1] = 1;
        
        y[frmy[i]]= 1;
        y[toy[i]]= 1;
        y[toy[i]+1] = 1;
    }
    
    int cnt = 0;
    for(auto &xxx : x) {
        xx[cnt] = xxx.uu;
        xxx.vv = cnt++;
    }
    cnt = 0;
    for(auto &yyy : y) {
        yy[cnt] = yyy.uu;
        yyy.vv = cnt++;
    }
    
//    for(auto xx : x) cout<<xx.uu<<" "<<xx.vv<<'\n';
//    for(auto yy : y) cout<<yy.uu<<" "<<yy.vv<<'\n';

    
//    cout<<'\n';
    for(int i =0 ; i < n ; i++ ) {
//        cout<<frmx[i]<<" "<<frmy[i]<<" "<<tox[i]<<" "<<toy[i]<<" -> ";
        
        frmx[i] = x[frmx[i]];
        frmy[i] = y[frmy[i]];
        
        tox[i] = x[tox[i]];
        toy[i] = y[toy[i]];
        
//        if(frmx[i] > tox[i]) swap(frmx[i] , tox[i]);
//        if(frmy[i] > toy[i]) swap(frmy[i] , toy[i]);
        
//        cout<<frmx[i]<<" "<<frmy[i]<<" "<<tox[i]<<" "<<toy[i]<<'\n';
    }
    
//    cout<<'\n';
}

vector<int>openy[MAX] , closey[MAX] ;
vector<pii> xaxis[MAX] , yaxis[MAX];

int tree[4*MAX];


void update(int node, int l , int r, int key , int val) {
    
    if(l > r || l > key || r < key) return;
    if(l == r) {
        tree[node]+= val;
        return;
    }
    
    int mid = (l+r)/2;
    update(node<<1 , l , mid , key , val);
    update(node<<1|1 , mid+1 , r , key , val);
    tree[node] = tree[node<<1] + tree[node<<1|1];
}

int query(int node , int l , int r , int frm ,int to) {
    
    if(l > r || l > to || r < frm) return 0;
    if(l >=frm && r<= to) return tree[node];
    
    int mid = (l+r)/2;
    int q1 = query(node<<1 , l , mid , frm ,to);
    int q2 = query(node<<1|1 , mid+1 , r , frm ,to);
    return (q1 + q2);
}

int main()
{
    fastRead;
    
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        cin>>frmx[i]>>frmy[i]>>tox[i]>>toy[i];
        if(frmx[i] > tox[i]) swap(frmx[i] , tox[i]);
        if(frmy[i] > toy[i]) swap(frmy[i] , toy[i]);
    }
    
    compress();
    
    for(int i =0 ; i < n ; i++ ) {
        
        if(frmx[i] == tox[i]) {
            openy[frmy[i]].push_back(i);
            closey[toy[i]].push_back(i);
            yaxis[frmx[i]].push_back({frmy[i] , toy[i] });
        }
        else {
            xaxis[frmy[i]].push_back({frmx[i] , tox[i]});
        }
    }
    
//    for(int i = 0 ; i <5 ; i++ ) {
//        cout<<i<<" -> ";
//        for(auto x : yaxis[i]) cout<<"( "<<x.uu<<" , "<<x.vv<<" ) ";
//        cout<<'\n';
//    }

//    for(int i =0 ; i < 10  ; i++  ) cout<<xx[i]<<" ";
//    cout<<'\n';
    
    int nn = 1e6;
    
    ll ans = 0;
    
    for(int i = 0 ; i <nn ; i++ ) {
        
        for(auto x: openy[i]) {
//            cout<<" -- "<<i<<" "<<frmx[x]<<'\n';
            
            tmpx[frmx[x]]++;
            
            if(tmpx[frmx[x]] ==1) update(1 , 0 , nn , frmx[x]  , 1);
        }
        
        sort(xaxis[i].begin() , xaxis[i].end());
        
        int last = -1;
        
        for(auto x : xaxis[i]) {
            
            int frm = max(last  + 1 , x.uu);
            int to = x.vv;
            
            ans += max(0 , xx[to]-xx[frm] +1);
            
            int ret = query(1 , 0 , nn , frm , to);
//            cout<<" ** "<<i<<" -> "<<frm<<" "<<to<<" "<<ret<<'\n';

            
            ans -= ret;
            
            last = max(to , last);
        }
        
        for(auto x : closey[i]) {
            tmpx[frmx[x]]--;
            
            if(tmpx[frmx[x]] == 0 ) {
                update(1 , 0 , nn , frmx[x] , -1);
            }
        }
//        cout<<i<<" "<<ans<<'\n';
    }
    
//    cout<<ans<<'\n';
    
    for(int i =0 ; i <nn ; i++ ) {
        
        sort(yaxis[i].begin() , yaxis[i].end());
        int last = -1;
        
        for(auto y : yaxis[i]) {
            int frm = max(last + 1 , y.uu);
            int to = y.vv;
            
            
            ans += max(0 , yy[to]-yy[frm] +1);
            
            last = max(to , last);            
        }
    }
    
    cout<<ans<<'\n';
    
    return 0;
    
}