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
int n , k , ara[MAX];
int main()
{
    fastRead;
    cin>>n>>k;
    for(int  i=1 ; i <= n ; i++ ) {
        cin>>ara[i];
    }
    sort( ara + 1 , ara + n  +1);
    if( k == 0 && ara[1]==1) cout<<-1<<endl;
    else if( ara[k] == ara[k+1]) cout<<-1<<endl;
    else cout<<max(1 , ara[k])<<endl;
    return 0;
}
