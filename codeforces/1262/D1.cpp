#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
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

ordered_set ost;



const int MAX = 1e6 + 6;

vector<pii>vec[MAX] , ara;

int n , ans[MAX];

bool comp(pii &p1 , pii &p2)  {

    if(p1.uu == p2.uu ) return p1.vv<p2.vv;
    return p1.uu > p2.uu;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i = 1 ; i <= n ; i++ ) {
        int tmp;
        cin>>tmp;
        ara.push_back({tmp , i});
    }
    
    sort(ara.begin() , ara.end() , comp);
    
    int q;
    cin>>q;
    for(int i =1 ; i <=q ; i++ ) {
        int k , pos;
        cin>>k>>pos;
        vec[k].push_back({pos, i});
    }
    
    
    for(int i = 0 ; i < n ; i++ ) {
        
        ost.insert({ara[i].vv , ara[i].uu});
        
        int len = i+1;
        
        for(auto x : vec[len]) {
            
            int pos = x.uu;
            int ansid = x.vv;
            
            ans[ansid] = (*ost.find_by_order(pos-1)).vv;
        }
    }
    
    for(int i =1 ; i <=q ;i++ ) cout<<ans[i]<<'\n';
    return 0;
}