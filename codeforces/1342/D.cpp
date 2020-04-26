#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
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

const int MAX = 2e5 + 5;
vector<int>ans[MAX];

int main() {
	
	fastRead;
	int n, k;
	cin>>n>>k;
	
	vector<int>ara(n) , rec(k+1);
	for(int i =0 ; i < n ;i++ ) cin>>ara[i];
	for(int i =1 ; i <=k ; i++) cin>>rec[i];
	sort(ara.rbegin() , ara.rend());
	
	ordered_set ost;
	int now = 0;
	
	for(auto x : ara ) {
        
        int mx = rec[x];
        
        int id = ost.order_of_key({mx , -1});
        
        if(id == 0 ) {
            ans[now].push_back(x);
            ost.insert({1,now});
            now++;
        }
        else {
            
            pii ret = *ost.find_by_order(id-1);
            ost.erase(ret);
            ans[ret.vv].push_back(x);
            ost.insert({ret.uu+1 , ret.vv});
        }
	}
	
	cout<<now<<'\n';
	for(int i =0 ; i < now ; i++ ) {
        cout<<ans[i].size()<<" ";
        for(auto x : ans[i]) cout<<x<<" ";
        cout<<'\n';
	}
	return 0;
}
