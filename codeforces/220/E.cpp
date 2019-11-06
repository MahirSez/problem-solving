#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e5 + 5;
ll   k , baam[4*MAX] , daan[4*MAX] , ara[MAX] , inv , ans ;
int nn = 1e5;
int n;

map<ll,ll>mp;


void updatedaan(int node ,int l , int r ,int key , int val) {
    
    if(l > r || l > key || r < key) return ;
    
    if(l == r) {
        daan[node] +=val;
        return;
    }
    int mid = (l+r)/2;
    updatedaan(node<<1 ,  l , mid , key , val);
    updatedaan(node<<1|1 , mid+1 , r , key  ,val);
    daan[node] = daan[node<<1] + daan[node<<1|1];
}

void updatebaam(int node , int l , int r , int key ,int val) {
    
    if(l > r || l > key || r< key) return;
    
    if(l == r) {
        baam[node] += val;
        return;
    }
    int mid = (l+r)/2;
    updatebaam(node<<1 , l , mid , key , val);
    updatebaam(node<<1|1 , mid+1 , r , key , val);
    baam[node] = baam[node<<1] + baam[node<<1|1];
}

ll maxlsum(int node, int l , int r , int frm , int to) {
    
    if(l > r || l > to || r< frm) return 0;
    
    if(l >= frm && r <= to ) return baam[node];
    
    int mid = (l+r)/2;
    ll q1 = maxlsum(node<<1 , l , mid , frm , to);
    ll q2 = maxlsum(node<<1|1 , mid+1 , r , frm , to);
    return q1 + q2;
}

ll minrsum(int node , int l , int r , int frm ,int to) {

    if(l > r || l > to || r < frm) return 0;
    
    if(l >= frm && r<= to) return daan[node];
    int mid = (l+r)/2;
    
    ll q1 = minrsum(node<<1 , l , mid , frm , to);
    ll q2 = minrsum(node<<1|1 , mid+1 , r , frm , to);
    return q1 + q2;
}



ll solve(int val) {
    
    ll q1 =  maxlsum(1  , 1 , nn , val + 1 , nn) ;
    ll q2 =  minrsum(1 , 1 , nn , 1 , val -1 );
    
//    cout<<val<<" "<<q1<<" "<<q2<<'\n';
    return q1 + q2;
}


ll wtf() {

    int l = 1 , r = 2;

    
    
    while(l < n ) {
        
        
        
        while(inv > k && r <= n ) {
            
            inv-= solve(ara[r]);
            updatedaan(1 , 1 , nn , ara[r] , -1);
            r++;
        }
        
//        cout<<" "<<l<<" "<<r<<" "<<inv<<'\n';
        
        
        if(r > n ) break;
        
        ans += (n-r+1);
        
        
//        cout<<l<<" "<<r<<" "<<" "<<inv<<" "<<ans<<'\n';
        
        l++;
        
        while(r <= l ) {
            
            inv -= solve(ara[r]);
            updatedaan(1 , 1 , nn ,  ara[r] , -1 );
            r++;
        }
        
        inv += solve(ara[l]);
        updatebaam(1 , 1 , nn , ara[l] , 1);
    }
    
    return ans;
}



int main()
{
    fastRead;

    cin>>n>>k;
    
    for(int i =1; i <=n ; i++ ) cin>>ara[i] , mp[ara[i]] = 1;
    
    int cnt = 0;
    
    for(auto &x : mp) {
        x.vv = ++cnt;
    }
    
    for(int i =1 ; i <=n ; i++ ) ara[i] = mp[ara[i]] ;
//    cout<<'\n';
    
    
    for(int i = n ; i >=1 ; i--) {
            
        updatedaan(1 , 1 , nn , ara[i] , 1);
        inv += solve(ara[i]);
    }
    
    inv -= solve(ara[1]);
    
    updatebaam(1 , 1 , nn , ara[1] , 1);
    updatedaan(1 , 1 ,  nn , ara[1] , -1);
    
    inv += solve(ara[1]);
    
    
    
    cout<<wtf()<<'\n';
    
    
    
    return 0;
    
}