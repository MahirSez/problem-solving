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
ll n, ara[MAX] , cnt ,a[3] , b[3];
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ;i++ ) cin>>ara[i];
    if( n <=2 ) {
        cout<<0<<endl;
        return 0;
    }
    a[0] = ara[0]-1;
    a[1] = ara[0];
    a[2] = ara[0]+1;

    b[0] = ara[1] -1;
    b[1] = ara[1];
    b[2] = ara[1]+1;
    bool flg ;
    ll ans = INF;
    for(int i =0 ; i < 3 ; i++ ) {
        for(int j = 0 ; j < 3 ;j++ ) {

            ll diff = a[i] - b[j];
            cnt = 0;
            if(i!=1) cnt++;
            if( j!=1) cnt++;

            ll prev = b[j];
            flg = true;
//            cout<<a[i]<<" "<<b[j]<<" ";
            for(int k = 2 ; k < n ; k++) {

                ll tmp = prev - diff;
//                cout<<tmp<<" ";

                if( abs( tmp - ara[k] ) > 1 ) {
                    flg  = false;
                    break;
                }
                prev = tmp;
                if( tmp != ara[k]) cnt++;
            }
//            cout<<endl;

            if(flg) ans = min( ans , cnt );
        }
    }
    if( ans != INF) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}
