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
int n;
map<ll, bool>mp;
ll ara[MAX];
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i];
        mp[ara[i]] = true;
    }
    sort( ara , ara + n ) ;
    for(int i =0 ; i < n ; i++ ) {

        for(int j = 1 ; (ara[i] + (1LL<<j)) <= ara[n-1] ; j++ )  {

            ll mask = (1LL<<j);
            ll tmp1 = ara[i] + mask;
            ll tmp2 = ara[i] + mask/2;
            if( mp[tmp1] && mp[tmp2] ) {
                cout<<3<<endl;
                cout<<ara[i]<<" "<<tmp1<<" "<<tmp2<<endl;
                return 0;
            }
        }
    }
    for(int i =0 ; i < n ; i++ ) {

        for(int j = 0 ; (ara[i] + (1LL<<j)) <= ara[n-1] ; j++ )  {

            ll mask = (1LL<<j);
            ll tmp1 = ara[i] + mask;
            if( mp[tmp1]  ) {
                cout<<2<<endl;
                cout<<ara[i]<<" "<<tmp1<<endl;
                return 0;
            }
        }
    }
    cout<<1<<endl;
    cout<<ara[0]<<endl;
    return 0;
}
