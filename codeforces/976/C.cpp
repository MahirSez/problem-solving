#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int n;
vector<pii>v;
map<pii , int>mp;

bool contains(pii p1 , pii p2  ) {
    ll l1 = p1.uu;
    ll r1 = p1.vv;

    ll l2 = p2.uu;
    ll r2 = p2.vv;

    return ( l1 <= l2 && r1>=r2);
}

bool comp(pii& p1 , pii& p2) {
    ll l1 = p1.uu;
    ll r1 = p1.vv;

    ll l2 = p2.uu;
    ll r2 = p2.vv;

    if( l1 == l2) return r1 > r2;
    return l1 < l2;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        ll a , b;
        cin>>a>>b;
        v.push_back({a,b});

        if( mp[{a,b}] ) {
            cout<<mp[{a,b}]<<" "<<i+1<<endl;
            return 0;

        }
        else mp[{a,b}] = i+1;
    }
    sort(v.begin() , v.end(), comp);
    for(int i =0 ; i < v.size() -1 ; i++ ) {

        if( contains(v[i] , v[i+1])) {

            cout<<mp[v[i+1]]<<" "<<mp[v[i]]<<endl;
            return 0;
        }
    }
    cout<<-1<<" "<<-1<<endl;
    return 0;
}
