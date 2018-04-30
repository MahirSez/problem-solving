#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int n , m , gph[5000][5000] , a , b;
ll ans;
vector<int>edg[MAX];
int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < m ; i++ ) {
        cin>>a>>b;
        gph[a][b] = 1;
        edg[a].push_back(b);
    }
    for(int  i = 1 ; i<= n ; i++ ) {
        for(int j =1 ;j <= n ; j++ ) {

            if(i == j)  continue;
            ll cnt = 0;

            for(int a = 0 ; a < edg[i].size() ; a++) {

                int node = edg[i][a];

                if( gph[node][j] ) cnt++;
            }

            ans += (cnt)*(cnt-1)/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}
