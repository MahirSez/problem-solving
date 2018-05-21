#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<ll,ll>
#define INF     	1e18
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int  n , m;
ll ara[MAX] , sum[MAX];
map<ll , pii>mp;
int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =1 ; i <= n ;i++ ) {
        cin>>ara[i];
        sum[i] = sum[i-1] + ara[i];
        mp[sum[i]] = {i , ara[i]};
    }
    while( m-- ) {
        ll tmp;
        cin>>tmp;
        if( mp[tmp].uu  ) {
            cout<<mp[tmp].uu<<" "<<mp[tmp].vv<<endl;
            continue;
        }
        int id = upper_bound(sum , sum + n+1 , tmp)- sum;
//        cout<<tmp<<" ->>"<<id<<" "<<sum[id-1]<<endl;
        cout<<id<<" "<<tmp - sum[id-1]<<endl;
    }
    return 0;
}
