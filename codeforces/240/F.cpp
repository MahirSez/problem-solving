#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("input.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("output.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int  n , m, tree[26][4*MAX] , lazy[26][4*MAX] ,rec[26];
string str;

void build(int node, int l , int r) {
    if( l == r ){
        tree[(str[l]-'a')][node] = 1;
        return;
    }
    int mid = (l+r)>>1;
    build( node<<1 , l , mid );
    build(node<<1|1 , mid+1 , r);
    for(int i =  0 ; i < 26 ; i++ ) {
        tree[i][node] = tree[i][node<<1] + tree[i][node<<1|1];
    }
}


void push(int node ,int l ,int r, int i) {
    if(lazy[i][node] !=-1) {
        tree[i][node] = lazy[i][node] * (r-l+1);
        if( l != r) {
            lazy[i][node<<1] = lazy[i][node];
            lazy[i][node<<1|1] = lazy[i][node];
        }
        lazy[i][node] = -1;
    }
}

void update(int node , int l , int r, int frm ,int to , int val ,int i) {
    push(node, l , r , i);
    if( l >r || l > to || r < frm) return;
    if( l>=frm && r <= to ) {
        lazy[i][node] = val;
        push(node, l , r,  i);
        return;
    }
    int mid = (l+r)>>1;
    update(node<<1 , l , mid , frm , to , val ,i);
    update(node<<1|1 , mid +1 , r ,frm , to , val , i );
    tree[i][node] = tree[i][node<<1] + tree[i][node<<1|1];
}

int query(int node, int l ,int r ,int frm , int to , int i) {
    push(node,  l , r, i);
    if( l > r || l > to || r< frm) return 0;
    if(l >=frm && r<= to ) {
        return tree[i][node];
    }
    int mid = (l+r)>>1;
    int q1 = query(node<<1 , l , mid , frm , to , i);
    int q2 = query(node<<1|1 , mid+1 , r , frm , to , i);
    return q1 + q2;

}
bool doable(int frm ,int to) {

    int cnt = 0;
    memset(rec , 0 ,sizeof rec);
    for(int i =0 ; i < 26 ; i++ ) {
        rec[i]= query(1 , 1 , n , frm , to , i);
        if(rec[i] & 1) {
            cnt++;
        }
    }
    return (cnt<=1);
}

int main()
{
    read;
    write;
    scanf("%d %d",&n,&m);
    cin>>str;
    str = "*" + str;
    memset( lazy , -1 , sizeof lazy);
    build(1 , 1 , n);
    while( m-- ) {
        int frm , to;
        scanf("%d %d",&frm,&to);
        if( !doable(frm , to) ) continue;
        int tmp = -1;
        int l = frm , r= to;
        for(int i =0 ; i < 26 ; i++ ) {
            if(rec[i]) update(1 ,1 , n , frm , to , 0 , i);
            int tot = rec[i];
            if( tot&1 ) {
                tmp = i;
            }
            tot/=2;
            if( tot == 0 ) continue;
            update(1 ,1 , n , l , l + tot-1 , 1 , i);
            update(1 ,1 , n , r-tot+1 , r , 1 , i );
            l+=tot;
            r-=tot;
        }
        if( tmp!=-1) {
            update(1, 1 , n , l , r , 1 , tmp);
        }
    }
    string ans="";
    for(int i =1  ; i <=n ; i++ ) {
        for(int j =0 ; j < 26; j++) {
            int get = query(1, 1 , n , i , i , j);
            if( get ) ans += (char)(j+'a');
        }
    }
    cout<<ans<<endl;
    return 0;
}

