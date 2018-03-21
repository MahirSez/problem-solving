#include <bits/stdc++.h>
#define ll			long long int
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
int n ,tmp , mx;
int used[MAX] ;
vector<int>edg[MAX];
vector<int>boss;

void dfs(int node, int lvl) {

    for(int  i=0 ; i < edg[node].size() ;i++ ){

        int x = edg[node][i];

        dfs(x , lvl +1);
    }

    mx = max(mx , lvl);
}

int main()
{
    cin>>n;
    for(int  i =1 ; i <= n ;i++ ) {

        cin>>tmp;
        if( tmp !=-1)
            edg[tmp].push_back(i);
        else
            boss.push_back(i);
    }

    for(int  i =0 ; i<boss.size(); i++ ) {

        dfs(boss[i], 1);
    }
    cout<<mx<<endl;
}
