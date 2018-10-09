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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

/*
	Order Statistics Tree ( OST )

	find_by_order()
		takes an integer k and returns an iterator to the k'th largest element counting from zero
	order_of_key()
		takes an element, here an integer and returns the number of elements strictly smaller than input
*/

typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int n , l[MAX] , r[MAX] , ara[MAX];
map<int,int>mp ;

ordered_set s;
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++) {
        cin>>ara[i];
        mp[ara[i]]++;
        l[i] = mp[ara[i]];
    }
    mp.clear();
    for(int i = n-1; i>=0 ; i--) {
        mp[ara[i]]++;
        r[i] = mp[ara[i]];

        s.insert({r[i] , i});
    }
//    for(int i = 0 ; i < n ; i++ ) {
//        cout<<ara[i]<<" "<<l[i]<<" "<<r[i]<<endl;
//    }
    ll ans = 0;

    for(int i =0 ; i < n ; i++ ) {
        int tmp = l[i];
        s.erase({r[i], i});
        ans += s.order_of_key({l[i],-1});
    }
    cout<<ans<<endl;
    return 0;
}
