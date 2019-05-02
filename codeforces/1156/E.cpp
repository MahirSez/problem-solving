#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n  , pos[MAX] , tree[4*MAX] , ara[MAX];


void build(int node , int l , int r) {

	if( l ==r) {
		tree[node] = ara[l];
		return ;
	}
	int mid = (l+r)>>1;
	build(node<<1 , l , mid);
	build(node<<1|1 , mid+1 , r);
	tree[node] = max(tree[node<<1] , tree[node<<1|1]);
}


int query(int node , int l , int r,  int frm , int to) {


    if( l > to || r < frm) return 0;

    if( l >=frm && r<=to) return tree[node];

    int mid = (l+r)>>1;
    int q1 = query(node<<1 , l , mid , frm ,to);
    int q2 = query(node<<1|1 , mid+1 , r , frm , to);
    return max(q1 , q2);
}

int solve(int frm , int to) {

    if( frm >= to) return 0;

    int val = query(1 , 1 , n , frm , to);

    int id = pos[val];

    int ans = solve(frm , id-1) + solve(id+1 , to);

    int l = id-frm , r = to- id;

    if( l < r) {

        for(int i= frm ; i< id ; i++ ) {

            int tgt = val - ara[i];

            int tgtid = pos[tgt];

            if( tgtid > id && tgtid <=to ) ans++;
        }
        return ans;
    }

    for(int i = id+1 ; i<=to ; i++ ) {

        int tgt = val - ara[i];

        int tgtid = pos[tgt];

		if( tgtid >= frm && tgtid < id) ans++;
    }
    return ans;

}


int main()
{
	fastRead;
	cin>>n;
	for(int i = 1; i<= n ; i++ ) {
		cin>>ara[i];
		pos[ara[i]] = i;
	}

	build(1 , 1 , n);

	cout<<solve(1 , n)<<endl;
	return 0;
}

