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
int n , m;
ll a[3003] , b[3003] ;

ll cnt1[3003] , cnt2[3003];
int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < n ; i++ ) cin>>a[i];
    for(int j =0 ; j < m ; j++ ) cin>>b[j];
    ll x;
    cin>>x;

    for(int i =0 ; i < n ; i++ ) {
        ll sum = 0;
        for(int j = i ; j< n ; j++ ) {
            sum += a[j];
            if(cnt1[j-i+1] == 0 ) cnt1[j - i + 1] = sum;
            else cnt1[j-i+1] = min( cnt1[j-i+1] , sum);
        }
    }

    for(int i =0 ; i < m ; i++ ) {
        ll sum = 0;
        for(int j = i ; j< m ; j++ ) {
            sum += b[j];
            if(cnt2[j-i+1] == 0 ) cnt2[j - i + 1] = sum;
            else cnt2[j-i+1] = min( cnt2[j-i+1] , sum);
        }
    }
    ll ans = 0;
    for(int i = 1 ; i <= n ; i++ ) {

        for(int j =1 ; j <= m ; j++ ) {

            if( cnt1[i] * cnt2[j] <= x) {
                ans = max( ans , 1LL*i*j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
