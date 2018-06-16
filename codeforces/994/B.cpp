#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll n , k ;
pair<pii, ll> ara[MAX];
vector<ll>v ;
vector<pii>str;
int main()
{
    fastRead;
    cin>>n>>k;
    for(ll i =0 ; i < n ; i++) {
        cin>>ara[i].uu.uu;
        ara[i].vv = i;
    }
    for(ll i =0 ; i < n ; i++ ) {
        cin>>ara[i].uu.vv;
    }
    sort( ara , ara + n);
    for(ll i =0 ; i < n ; i++ ) {
        ll ans = ara[i].uu.vv;
        for(ll j = 0 ; j < k && j < v.size() ; j++ ) {
            ans += v[j];
        }
        str.push_back({ara[i].vv ,ans });

        v.push_back(ara[i].uu.vv);
        sort(v.rbegin() , v.rend() ) ;
        while((int)v.size() > 15) {
            v.pop_back();
        }
    }
    sort( str.begin() , str.end());
    for(ll i =0 ; i < str.size() ; i++ ) {
        cout<<str[i].vv<<" ";
    }
    cout<<endl;
    return 0;
}
