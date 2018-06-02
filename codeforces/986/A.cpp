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
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m , k , s , dst[MAX] , col[MAX] ,ans[MAX][200];
vector<int>edg[MAX];

void bfs(int tgt) {

    queue<int>q;
    for(int i =0 ; i < n ; i++ )
        dst[i] = INF;
    for(int i =0 ; i < n ; i++ ) {
        if( col[i] == tgt) {
            dst[i] = 0;
            q.push(i);
        }
    }
    while( !q.empty() ) {
        int top = q.front();
        q.pop();
        for(int i =0 ; i < edg[top].size() ; i++ ) {
            int node = edg[top][i];
            if( dst[node] > dst[top] + 1) {
                dst[node] = dst[top] + 1;
                q.push(node);
            }
        }
    }
//    cout<<tgt<<endl;
//    for(int i =0 ; i < n ; i++ ) cout<<dst[i]<<" ";
//    cout<<endl;
    for(int i =0 ; i < n ; i++ )
        ans[i][tgt] = dst[i];
}

int main()
{
    fastRead;
    cin>>n>>m>>k>>s;
    for(int i =0 ; i < n ; i++ ) {
        cin>>col[i];
        col[i]--;
    }
    for(int i =0 ; i < m ;i++ ) {
        int u , v;
        cin>>u>>v;
        u-- , v--;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }

    for(int i =0 ; i < k ; i++ ) {
        bfs(i);
    }
    for(int i =0 ; i < n ;i++  ) {
        int sum = 0;
        sort( ans[i] , ans[i] + k);
        for(int j = 0; j < s ; j++ )
            sum += ans[i][j];
        cout<<sum<<" ";
    }
    cout<<endl;
    return 0;
}
