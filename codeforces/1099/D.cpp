#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e12
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
vector<int>edg[MAX];
ll val[MAX];

ll ans = 0;
bool ok;

void dfs2(int node ,ll sum) {

    if( val[node] != INF) {
        if( val[node] < sum ) {
            ok = false;
            return;
        }
        else ans += val[node] - sum;
    }

    for( auto x : edg[node]) {
        dfs2(x , val[node]);
    }
}

void dfs1(int node ) {

    ll tmp = val[node];

    if( tmp == -1) {
        tmp = INF;

        for(auto x : edg[node]) tmp = min(tmp , val[x]);
        val[node] = tmp;
    }

    for(auto x : edg[node]) dfs1(x);

}


int main()
{
    fastRead;
    cin>>n;
    for(int i =2 ; i <= n ; i++) {
        int tmp;
        cin>>tmp;
        edg[tmp].push_back(i);
    }
    for(int i =1 ; i <=n ; i++ ) cin>>val[i];
    ok = true;

    dfs1(1 );
//
//    for(int i =1 ; i<= n ; i++ ) {
//        cout<<val[i]<<" ";
//    }
//    cout<<endl;



    dfs2(1,0);

    if( ok) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}
