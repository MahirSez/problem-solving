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
int n ;
vector<pii>v;
vector<int>edg[202];
int  lvl[202];
int maxLvl , id;

void dfs(int node, int par , int lev) {
    lvl[node] = lev;
    if( lev > maxLvl) {
        maxLvl = lev;;
        id = node;
    }
    for(int i =0 ; i < edg[node].size() ; i++ ) {
        int x = edg[node][i];
        if( x == par) continue;
        dfs(x , node , lev+1);
    }
}


void print() {
    for(int i =1 ; i<= n ;i++ ) {
        cout<<lvl[i]<<" ";
    }
    cout<<endl;
}
int solve() {
//    cout<<"---"<<endl;
    maxLvl = -1 , id = -1;
    memset( lvl , -1 ,sizeof lvl);
    for(int i =1 ;i<= n ; i++ ) {
        if( lvl[i] == -1 ) {
            dfs(i , -1 , 0);
            break;
        }
    }

    memset(lvl , -1 , sizeof lvl );

    dfs(id , -1 , 0);
    int ans = maxLvl;
    maxLvl = -1 , id = -1;

    for(int i =1 ; i<= n ;i++ ) {
        if( lvl[i] == -1 ) {
            dfs(i , -1 , 0);
        }
    }
    memset(lvl , -1 , sizeof lvl);
    dfs(id , -1 , 0);
    ans *= maxLvl;
    return ans;

}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n-1 ; i++ ) {
        int x , y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    int ans =0;
    for(int i = 0 ; i < n -1 ; i++ ) {
        for(int i =0 ; i <=200 ; i++ ) edg[i].clear();

        for(int j = 0  ; j < n-1 ; j++ ) {

            if(  i == j ) continue;
            int x = v[j].uu;
            int y = v[j].vv;
            edg[x].push_back(y);
            edg[y].push_back(x);
        }
        int tmp = solve() ;
        ans = max( ans , tmp);
    }
    cout<<ans<<endl;
    return 0;
}
