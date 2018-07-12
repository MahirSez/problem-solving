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
int n , ara[MAX] , q;
map<int, ll>nwDiv , oldDiv , ans;
int main()
{
    fastRead;
    cin>>n;
    for(int i= 0 ; i < n ; i++ ) cin>>ara[i];

    for(int i =0 ; i < n ; i++ ) {

        nwDiv.clear();
        map<int,ll>::iterator it;
        for(it = oldDiv.begin() ; it != oldDiv.end() ; it++ ) {
            nwDiv[__gcd(ara[i] , it->uu)] += it->vv;
        }
        nwDiv[ara[i]]++;

        for(it = nwDiv.begin() ; it != nwDiv.end() ; it++ ) {
            ans[it->uu] += it->vv;
        }
        swap(oldDiv , nwDiv);
    }
    cin>>q;
    while( q-- ) {
        int tmp;
        cin>>tmp;
        cout<<ans[tmp]<<'\n';
    }
    return 0;
}
