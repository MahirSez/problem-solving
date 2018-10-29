#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<ll,ll>
#define ppi         pair<pii , ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int  n,  m;
struct touple {
    ll uu , vv ;
    int id;
} ara[MAX];
ll ans[MAX], sumL , sumR;

bool comp(touple x , touple y) {
    return x.uu + y.vv < x.vv + y.uu;
}


int main()
{
    fastRead;
    cin>>n>>m;
    for(int i = 1; i <= n ;i++ ) {
        cin>>ara[i].uu>>ara[i].vv   ;
        ara[i].id = i;
        sumR += ara[i].vv;
    }
    for(int i =0 ; i < m ;i++) {
        int u , v;
        cin>>u>>v;
        ll tmp = ara[u].uu + ara[v].vv;
        tmp = min( tmp , ara[u].vv + ara[v].uu ) ;
        ans[u] -= tmp;
        ans[v] -= tmp;
    }

    sort( ara + 1  , ara + n + 1 , comp);

    for(int  i=1 ; i <= n ;i++ ) {

        int id = ara[i].id;

        sumR -= ara[i].vv;
        ans[id] += sumR + sumL;
        sumL += ara[i].uu;

        ans[id] += (ara[i].uu * (n-i) );
        ans[id] += (ara[i].vv * (i-1) );
    }
    for(int i =1 ; i<= n ; i++ ) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
