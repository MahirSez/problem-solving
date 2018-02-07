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
int n , m ,ans;
string str;
vector<int>edg[MAX];
int vis[MAX];
int dp[MAX][26];

bool dfs(int x) {
    int take[26];
    memset(take , 0 , sizeof(take));

    if( vis[x] == 1) return false;

    if( vis[x] == 0) {

        vis[x] = 1;
        for( int  i =0 ; i < edg[x].size() ; i++ ) {

            int node = edg[x][i];
            bool flg1 = dfs(node);
            if(flg1 == false) return false;

            for( int  j=0 ; j < 26; j++) {

                take[j] = max( take[j] ,dp[node][j] );
            }
        }
        dp[x][str[x-1] - 'a'] = 1;
        for( int i =0 ; i < 26; i++ ) {
            dp[x][i] += take[i];
            ans = max(dp[x][i] , ans);
        }

    }
    vis[x] = 2;
    return true;
}

int main()
{
    cin>>n>>m;
    cin>>str;
    for( int  i=0 ; i< m ; i++ ) {
        int a , b;
        scanf("%d %d",&a,&b);
        edg[a].push_back(b);
    }
    int flg = true;
    for( int i =1 ; i <= n ; i++ ) {

        if( vis[i]  == false) {
            flg = dfs(i);
        }
        if( flg == false) break;
    }
    if( flg == false) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
