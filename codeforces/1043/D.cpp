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
int n , m , nxt[MAX] , ara[MAX] , tmp[MAX];
int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];

    for(int i = 0 ; i< n-1 ; i++ ) {
        nxt[ara[i]] = ara[i+1];
    }
    nxt[ara[n-1]] = -1;

    for(int a =1 ; a < m ; a++ ) {

        for(int i =0 ; i < n ; i++ ) cin>>tmp[i];

        for(int i =0 ; i <n-1; i++ ) {

            if( nxt[tmp[i]] != tmp[i+1] ) {
                nxt[tmp[i]] = -1;
            }
        }
        nxt[tmp[n-1]] = -1;
    }


    ll ans = 0;
    int i = 0;
    while(i < n) {

        ll cnt = 1;

        while( i < n && nxt[ara[i]] != -1 ) {
            cnt++;
            i++;
        }
        i++;
//        cout<<ara[i]<<" "<<cnt<<endl;

        ans += ( (cnt*(cnt+1))/2 );

    }
    cout<<ans<<endl;
    return 0;
}
