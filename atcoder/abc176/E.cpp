#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

map<int , int>romp , colmp ;
map<pii, int> mp;


vector<int>rec[N];
int ara[N], tree[4*N];

void build(int node , int l , int r) {
    if(l == r) {
        tree[node] = ara[l];
        return;
    }
    int mid = (l+r)/2;
    build(node<<1, l , mid);
    build(node<<1|1 , mid+1 , r);
    tree[node] = max(tree[node<<1] , tree[node<<1|1]);
}

void update(int node, int l , int r , int id , int val) {
    if(l > r || l > id || r < id)return ;
    if(l == r) {
        tree[node] += val;
        return;
    }
    int mid = (l+r)/2;
    update(node<<1 , l ,mid , id , val);
    update(node<<1|1 , mid+1 , r , id , val);
    tree[node] = max(tree[node<<1] , tree[node<<1|1]);
}

int main()  {
    fastio;
    
    
    int n , m , cnt;
    cin>>n>>m>>cnt;
    while(cnt -- ) {
        int x , y;
        cin>>x>>y;
        rec[x].push_back(y);
        ara[y]++;
    }  

    int nn = 3e5;
    build(1 ,1 , nn );

    int ans = 0;
    for(int i = 1 ; i <= nn ; i++ ) {
        for(auto x : rec[i]) update(1 ,1 , nn , x , -1);
        ans = max(ans , (int)rec[i].size() + tree[1] );
        for(auto x : rec[i]) update(1 ,1 , nn , x , 1);
    }
    cout<<ans<<'\n';

    
    
    return 0;
    
}