#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll n ,m, k  , str[MAX];
pii ara[MAX] ;
int cnt[MAX];
vector<ll>edg[MAX];
int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =1 ; i <= n ;i++ ) {
        cin>>ara[i].uu ;
        ara[i].vv = i;
        str[i] = ara[i].uu;
    }
    sort(ara +1, ara + n+1);
    for(int  i= 2 ; i <n+1 ;i++  ) {
        if( ara[i].uu > ara[i-1].uu ) {
            cnt[ara[i].vv] = i-1;
        }
        else {
            cnt[ara[i].vv] = cnt[ara[i-1].vv] ;
        }
    }
    for(int i =0 ; i < m ;i++ ) {
        int u , v;
        cin>>u>>v;
        if( str[u] > str[v] ) cnt[u]--;
        else if( str[v] > str[u]) cnt[v]--;
    }
    for(int i = 1; i <= n ; i++ ) cout<<cnt[i]<<" ";
    cout<<endl;
    return 0;
}
