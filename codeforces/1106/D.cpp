#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m ;
vector<int>edg[MAX];
int vis[MAX];
int main()
{
    fastRead;
    cin>>n>>m;
    while( m--) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    priority_queue<int , vector<int> , greater<int> >pq;
    pq.push(1);
    vis[1] = true;

    while( !pq.empty()) {
        int top = pq.top();
        cout<<top<<" ";

        pq.pop();
        for(auto x : edg[top]){
            if( vis[x]) continue;
            vis[x] = 1;
            pq.push(x);
        }
    }
    cout<<endl;
    return 0;
}
