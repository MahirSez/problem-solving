#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS     1e-8
#define MAX     1000006
#define MOD     1000000007
using namespace std;
int n , m , tot, key , val;
int tree[MAX] , ara[MAX] , lev[MAX];

void build(int node , int b ,int e) {

    if( b == e) {

        tree[node] = ara[b];
        lev[node] = 1;
        return;
    }


    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) /2;

    build( left , b  ,mid);
    build(right , mid + 1 , e);

    lev[node] = lev[left] + 1;
    if( lev[node] & 1 ) tree[node] = tree[left] ^ tree[right];
    else tree[node] = tree[left] | tree[right];
}

void update(int node ,int b ,int e) {
    //cout<<key<<" "<<val<<" range = "<<b<<" "<<e<<endl;
    if( b > key || e < key )  return;
    if( b == e) {
        tree[node] = val;
        //cout<<b<<" "<<e<<" "<<val<<" val "<<tree[val]<<endl;
        return;
    }
    //cout<<"HELLO FROM"<<endl;
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (b + e) /2;

    update( left , b  ,mid);
    update(right , mid + 1 , e);

    if( lev[node] & 1 ) tree[node] = tree[left] ^ tree[right];
    else tree[node] = tree[left] | tree[right];
}

void print() {

    for(int  i =1 ; i < tot<<1; i++)
        cout<<i<<" = "<<tree[i]<<" lev= "<<lev[i]<<endl;
    cout<<endl;
}

int main()
{
    cin>>n>>m;
    tot= 1<<n;
    for(int  i =1 ; i <= tot ; i++ )
        scanf("%d",&ara[i]);
    build(1,1,tot);
    //print();
    while(m-- ) {

        scanf("%d %d",&key , &val);
        update(1,1,tot);
        //print();
        printf("%d\n",tree[1]);
    }
    return 0;
}
