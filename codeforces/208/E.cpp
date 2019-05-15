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
int n ,_time , st[MAX] , en[MAX] , par[MAX] , table[MAX][20] , level[MAX];
vector<int>lvl[MAX] , edg[MAX] ;

void dfs(int node , int lev) {


	level[node] = lev;
    st[node] = ++_time;
    lvl[lev].push_back(_time);

    for(auto x : edg[node]) {

		table[x][0] = node;
        dfs(x , lev+1);
    }
    en[node] = ++_time;
}
void build() {


    for(int i = 1 ; (1<<i) <= n ; i++ ) {

        for(int j = 1 ; j <= n ; j++ ) {

            if( table[j][i-1] != -1) {
                table[j][i] = table[ table[j][i-1] ][i-1];
            }
        }
    }
}

int getPar(int node , int k) {

	for(int i = 20 ; i >= 0 ; i-- ) {

        if( (1<<i) <=k && table[node][i] != -1) {
            node = table[node][i];
            k -= (1<<i);
        }
	}
	if( k != 0) return -1;
    return node;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i <=n ; i++ ) {
		int p;
		cin>>p;
        edg[p].push_back(i);
    }

	memset(table , -1 , sizeof table);
    dfs(0 , 0);

	build();


    int m;
    cin>>m;
    while( m-- ) {

        int v , p;
        cin>>v>>p;
        int pp = getPar(v , p);
        if(pp <=0 ) {
			cout<<0<<" " ;
			continue;
        }

        int h = level[v];

        int it1 = lower_bound( lvl[h].begin() , lvl[h].end() , st[pp]) - lvl[h].begin();
        int it2 = upper_bound( lvl[h].begin() , lvl[h].end() , en[pp]) - lvl[h].begin();

		cout<<it2-it1-1<<" ";
    }

	cout<<endl;
	return 0;

}
