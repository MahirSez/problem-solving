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
multiset<ll>st;
int n , k;

vector<ll>v;
int main()
{
	fastRead;
	cin>>n>>k;
    for(int i =0 ; i < n ; i++ ) {
        ll tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    sort(v.begin() , v.end() );

    int s = 0;
    int e = (n-1)/2 + 1;
    int ans = 0;
//    cout<<s<<" "<<e<<endl;

//    cout<<v[s]<<" "<<v[e]<<endl;

	while( e < n) {

        if( v[e] - v[s] >= k) ans++ , s++;
        e++;
	}

    cout<<ans<<'\n';
    return 0;
}
