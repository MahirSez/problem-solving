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
int n  , par[MAX] , ara[MAX] ,cnt[MAX];
pii pr[MAX] ;
int ans = INF;
multiset<int>ms;
int rep(int x) {
    return ( par[x] == x ) ? x : par[x] = rep(par[x]);
}

void join(int a , int b) {
    par[rep(b)] = rep(a) ;
}
int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i <= n ;i++ ) {
        cin>>ara[i];
        pr[i].uu = ara[i];
        pr[i].vv = i;
    }
    ara[0] = ara[n+1] = INF;
    sort( pr +1, pr + n +1);
    int mx = -1;
    for(int i = 1 ;i<= n ; i++ ) {

        int id = pr[i].vv;
        par[id] = id , cnt[id] = 1;
        if( ara[id] > ara[id-1]) {

            int boss = rep(id-1);
            ms.erase( ms.find( cnt[boss] ) ) ;
            cnt[id] += cnt[boss];
            join( id , id  - 1 );
        }
        if( ara[id] > ara[id+1] ) {

            int boss = rep(id+1);
            ms.erase( ms.find( cnt[boss] ) ) ;
            cnt[id] += cnt[boss];
            join( id , id + 1 );
        }
        ms.insert(cnt[id]);
        if( *ms.begin() == *ms.rbegin() ) {
            if( (int)ms.size() > mx) {
                mx = ms.size();
                ans = ara[id] ;
            }
        }
    }
    cout<<ans + 1<<endl;
    return 0;
}
