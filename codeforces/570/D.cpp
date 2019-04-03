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
int n , m;
vector<int>edg[MAX] ,msk[MAX];
vector<pii> lvl[MAX];
string str;
int vis[MAX] , fin[MAX];
int tim;


void dfs(int node, int lev) {

    vis[node] = ++tim;
    lvl[lev].push_back({tim , node});
    for(auto x : edg[node]) {
		dfs(x, lev+1);
    }
    fin[node] = ++tim;
}

bool query(int node , int lev) {

    int frm = vis[node];
    int to = fin[node];

//	cout<<node<<" "<<lev<<" -> "<<endl;
//    for(auto x: lvl[lev]) {
//		cout<<x.vv<<" ";
//    }
//	cout<<lev<<" "<<lvl[lev].size()<<endl;
	if(lvl[lev].size()==0) return true;

    int id1 = lower_bound(lvl[lev].begin() , lvl[lev].end() , pii(frm,0) ) - lvl[lev].begin() -1;
    int id2 = lower_bound(lvl[lev].begin() , lvl[lev].end() , pii(to,0) ) - lvl[lev].begin() -1;

    int a =0, b =0;
    if(id1 >=0 ) a = msk[lev][id1];
    if( id2 >=0 ) b = msk[lev][id2];

    int tmp = a^b;

    return (__builtin_popcount(tmp) <= 1 );
}


int main()
{
	fastRead;
	cin>>n>>m;
	for(int i =2 ; i<=n ; i++ ) {
        int tmp;
        cin>>tmp;
        edg[tmp].push_back(i);
	}

	dfs(1,1);

//	for(int i = 1 ; i<= n ; i++) {
//		cout<<i<<" -> ";
//		for(auto x : lvl[i]) {
//			cout<<x.vv<<" "<<x.uu<<endl;;
//		}
//		cout<<endl;
//	}
	cin>>str;

    str = '*' + str;


    for(int i = 1 ; i<= n ; i++ ) {

        int mask = 0;
        for(auto x : lvl[i]) {

            int node = x.vv;

            int id = str[node]-'a';

            mask = (mask ^ (1<<id) );
            msk[i].push_back(mask);
        }
    }
	while( m-- ) {

        int node , lev;
        cin>>node>>lev;
        bool ok = query(node , lev);
        if(ok) cout<<"Yes\n";
        else cout<<"No\n";
	}
	return 0;
}
