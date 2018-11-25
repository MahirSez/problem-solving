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
int n , ara[MAX] ,deg[MAX];
vector<int>edg[MAX];

void dfs(int node , int par) {
    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if( x== par) continue;
        dfs(x , node);
        ara[node] += ara[x];
    }
}

int main()
{
    fastRead;
    cin>>n;
    if( n ==1 ) {
        cout<<1<<endl;
        return 0;
    }
    for(int i =2 ; i <= n ; i++ ) {
        int tmp;
        cin>>tmp;
        deg[tmp]++;
        deg[i]++;
        edg[tmp].push_back(i);
        edg[i].push_back(tmp);
    }
    for(int i = 2; i<=n ; i++ ) {
        if( deg[i] ==1 ) ara[i] = 1;
    }
    dfs(1 , 0);
    sort(ara +1, ara + n + 1);
    for(int i = 1 ; i<= n ; i++ ) {
        cout<<ara[i]<<" ";
    }
    cout<<endl;
}
