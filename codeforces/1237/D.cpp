#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 2e5 + 5;

int n , ara[MAX] , ans[MAX] , mn[MAX] , mx[MAX];
int tree[2][4*MAX] ;

void build(int node , int l , int r) {

    if(l == r)  {
        tree[0][node] = tree[1][node] = ara[l];
        return;
    }
    int mid = (l+r)/2;
    build(node<<1 , l , mid);
    build(node<<1|1 , mid+1 , r);
    tree[0][node] = min(tree[0][node<<1] , tree[0][node<<1|1]);
    tree[1][node] = max(tree[1][node<<1] , tree[1][node<<1|1]);
}

int query(int node , int l , int r , int frm , int to, int flg) {
    
    if(l > r || l > to || r < frm) {
        if(flg) return 0;
        return INF;
    }
    
    if(l >=frm && r <= to) {
        return tree[flg][node];
    }
    int mid = (l+r)/2;
    int q1 = query(node<<1 , l , mid , frm , to, flg);
    int q2 = query(node<<1|1 , mid+1 , r , frm , to , flg);
    
    if(flg) return max(q1 , q2);
    return min(q1 , q2);
}


int getMax(int id) {

    
    int ret = -1;
    
    int lo = id+1 , hi = 2*n;
    while(lo <= hi) {
        
        int mid = (lo+hi)/2;
        int val = query(1 , 1 , 2*n , id+1 , mid , 1);
        if(val > ara[id]) {
            ret = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    
    return ret;
}
int getMin(int id) {
    
        
    int ret = -1;
    
    int lo = id+1 , hi = 2*n;
    while(lo <= hi) {
        
        int mid = (lo+hi)/2;
        int val = query(1 , 1 , 2*n , id+1 , mid , 0);
        
        if(2*val < ara[id]) {
            ret = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    
    return ret;
}

int main()
{
    fastRead;
    cin>>n;
    vector<pii>vec;
    
    for(int  i =1 ; i <=n ; i++ ) {
        cin>>ara[i];
        vec.push_back({ara[i] , i});
        ara[i+n] = ara[i];
    }
    
    build(1 , 1 , 2*n);
    
    for(int i =1; i <=n ; i++ ) {
        
        mx[i] = getMax(i);
        mn[i] = getMin(i);
        
//        cout<<mn[i]<<" "<<mx[i]<<'\n';
    }
    sort(vec.rbegin() , vec.rend());
    bool allneg = false;
    
    for(auto x : vec) {
        
        
        int id = x.vv;
        int val = x.uu;
//        cout<<id<<" "<<val<<'\n';
        
        int mxID = mx[id];
        int mnID = mn[id];
        
        
        if(mxID != -1 && mnID !=-1) {
            
            
            if(mxID > mnID) ans[id] = mnID - id;
            else ans[id] = ans[mxID] + mxID - id;
        }
        else if(mnID != -1 ){
            ans[id] = ans[id] = mnID - id;
        }
        else if(mxID != -1) {
            ans[id] = ans[mxID] + mxID - id;;
        }
        else {
            allneg = true;
            break;
        }
        
        ans[id+n] = ans[id];
    }
    
    if(allneg) {
        for(int i =0 ; i < n ; i++ ) cout<<-1<<" ";
        cout<<'\n';
        return 0;
    }
    
    for(int i =1; i <=n ; i++ ) cout<<ans[i]<<" ";
    cout<<'\n';
    
    
    return 0;
}