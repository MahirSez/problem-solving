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
int k , n ;
map<ll,pii>mp;
map<ll,bool>taken;
ll ara[MAX];
int main()
{
    fastRead;
    cin>>k;
    for(int t = 1 ; t <= k ; t++ ) {
        cin>>n;
        ll sum = 0;
        for(int i = 1 ; i <= n ; i++ ) {
            cin>>ara[i];
            sum += ara[i];
        }
        for(int i =1 ; i <= n ; i++ ) {
            ll tmp = sum - ara[i];
            if( taken[tmp] ) {

                if( mp[tmp].uu != t) {
                    cout<<"YES"<<endl;
                    cout<<mp[tmp].uu<<" "<<mp[tmp].vv<<endl;
                    cout<<t<<" "<<i<<endl;
                    return 0;
                }
            }
            else {
                taken[tmp] = true;
                mp[tmp].uu = t;
                mp[tmp].vv = i;
            }
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
