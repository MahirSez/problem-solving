#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n;
ll sub[MAX] , ans , m;
vector<int>edg[MAX];

void dfs(int node ,int par ) {

    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if(x == par) continue;
        dfs(x , node);
        sub[node] += sub[x];
//        cout<<"----->"<<node<<" "<<sub[node]<<endl;
        ans += min( sub[x] , 2*m - sub[x] );
    }
}

int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < 2*m ; i++ ) {
        int tmp;
        cin>>tmp;
        sub[tmp] = 1;
    }
    for(int i =0 ; i < n -1 ; i++ ) {
        int a , b ;
        cin>>a>>b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }
    dfs(1 , -1);
    cout<<ans<<endl;
    return 0;
}
