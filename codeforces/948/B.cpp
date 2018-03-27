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
int x ;
int flg[MAX];
vector<int>prime;

int main()
{
    for(int i = 2 ; i< MAX ; i++ ) {

        if( flg[i] ) continue;

        for(int j = i ; j < MAX; j+=i )
            flg[j] = max( flg[j] , i);
    }


    for(int i = 2; i < MAX ; i++) {

        if( flg[i] == i) continue;
        flg[i] = i - flg[i] + 1;
    }

    cin>>x;

    int ans = INF;

    for(int i = flg[x] ; i <= x ; i++) {

        ans = min( ans , flg[i] );
    }
    cout<<ans<<endl;
    return 0;
}
