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
int n ,sub[MAX] , par[MAX];
vector<int>edg[MAX];
int best , semiBest , bestID;

void dfs1(int node , int par) {
    sub[node] = 1;
    for(int  i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if(x == par) continue;
        dfs1(x , node);
        sub[node] += sub[x];
    }
}

int dfs2(int node , int par) {
    for(int i = 0 ; i < edg[node].size() ; i++ )  {
        int x = edg[node][i];
        if( x == par) continue;
        if( sub[x] > n/2) return dfs2(x , node);
    }
    return node;
}

void dfs3(int node , int parent) {
    sub[node] =1;
    if( parent != -1) {

        if(par[parent] == -1) {
            par[node] = node;
        }
        else par[node] = par[parent];
    }
    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if( x == parent) continue;
        dfs3(x , node);
        sub[node] += sub[x];
    }
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n -1 ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    dfs1(1 , -1);
    int r = dfs2(1 , -1);
    memset( par , -1 , sizeof par);
    dfs3(r , -1);

    for(int i = 1; i<= n ; i++ ) {
        if(par[i] != i) continue;
        if(sub[i] > best) {
            bestID = i;
            semiBest = best;
            best = sub[i];
        }
        else if( sub[i] > semiBest ) {
            semiBest = sub[i];
        }
    }
    for(int i= 1 ;i<= n ; i++ ) {
        if( i == r) {
            cout<<1<<" ";
            continue;
        }
        int sz = 0;
        if(par[i] == bestID) {
            sz = min(n - sub[i] - semiBest ,  n - sub[par[i]] );
        }
        else {
            sz = n - sub[i] -best;
        }
        if( sz <=n/2 ) {
            cout<<1<<" ";
        }
        else cout<<0<<" ";
    }
    cout<<endl;
    return 0;
}
