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
int n , m , par[MAX] , sz[MAX];


int boss(int x) {

    return (par[x] == x ? x : par[x] = boss(par[x]));
}
int main()
{
    fastRead;
    cin>>n>>m;
    for(int i = 1 ; i<=	 n ; i++ ) par[i] = i , sz[i] = 1;
	while( m-- ) {

        int nn;
        cin>>nn;

        if( nn ==0 ) continue;

        int tmp;
        cin>>tmp;

        int parT = boss(tmp);

        for(int i = 1 ; i< nn ; i++ ) {

            cin>>tmp;
            int parY = boss(tmp);
            if( parY == parT) continue;

//            cout<<parY<<" "<<sz[parY]<<" - "<<parT<<" "<<sz[parT]<<endl;
            par[parY] = parT;

            sz[parT] += sz[parY];
//            cout<<parY<<" "<<sz[parY]<<" - "<<parT<<" "<<sz[parT]<<endl;
        }
	}

	for(int i =1 ; i <= n ; i++ ) {

        int parI = boss(i);
        cout<<sz[parI]<<" ";
	}
	cout<<endl;
	return 0;
}
