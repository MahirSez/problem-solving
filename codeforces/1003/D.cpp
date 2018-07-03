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
int n , q  , ara[100];
int ok[100];
int main()
{
    fastRead;
    cin>>n>>q;
    while( n -- ) {
        int tmp;
        cin>>tmp;
        int cnt = 0;
        while(tmp>>=1) {
            cnt++;
        }
        ara[cnt]++;
    }

    while( q-- ) {
        int tmp;
        cin>>tmp;
        int ans =0;
        for(int i = 31 ; i>=0 && tmp > 0; i-- ) {
            if( ara[i]==0 || (1<<i) > tmp ) continue;
            int cnt = tmp / (1<<i);
            cnt = min( cnt , ara[i]);
            tmp = tmp - (1<<i) * cnt;
            ans += cnt;
        }
        if( tmp ==0) printf("%d\n",ans);
        else printf("-1\n");
    }
    return 0;
}
/**
3 10
2 2 8
*/
