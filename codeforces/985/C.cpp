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
ll n , k , l ,ara[MAX];
bool mrk[MAX];
int main()
{
    fastRead;
    cin>>n>>k>>l;
    for(int i = 0 ; i < n*k ; i++ ) cin>>ara[i];
    sort( ara , ara + n*k );

    int id = upper_bound(ara , ara + n*k , ara[0] + l ) -ara;
    if( id < n) {
        cout<<0<<endl;
        return 0;
    }
    id--;
    int frm = id - n + 2 , to = id;
    ll ans = ara[0] , cnt = 1;
    for(int i =1  ; i < frm ; i++ ,cnt++) {

        if( cnt == k ) {
            cnt = 0;
            ans +=ara[i];
            frm++;
        }
    }
    for(int i = frm ; i <= to ; i++ ) ans +=ara[i];
    cout<<ans<<endl;
    return 0;
}
