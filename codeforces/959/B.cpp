#include <bits/stdc++.h>
#define ll          long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e15
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
ll n , m , k ,ans;
ll ara[MAX];
string sara[MAX];
vector<ll>edg;
map<string,ll>mp;

int main()
{
    fastRead;
    cin>>n>>k>>m;
    for(int  i=1 ; i <= n ;i++ ) {
        cin>>sara[i];
    }

    for(int  i=1 ; i <= n ;i++) {

        cin>>ara[i];
    }

    for(int i =0 ; i < k ;i++ ) {

        ll tmp;
        cin>>tmp;
        ll val  = INF;
        edg.clear();
        for(int j = 0 ; j < tmp ; j++ ) {

            ll a ;
            cin>>a;
            edg.push_back(a);
            val = min( val , ara[a] );
        }

        for(int j = 0 ; j< tmp ; j++ ) {

            ll node = edg[j];
            string s = sara[node];
            mp[s] = val;
        }
    }
//    for(int i =1 ;i<= n ;i++ ) {
//
//        cout<<sara[i]<<" "<<mp[sara[i]]<<endl;
//    }
//    cout<<endl;
    for(int i =0 ; i < m ;i++ ) {

        string str;
        cin>>str;
        ans += mp[str];
    }

    cout<<ans<<endl;
    return 0;

}



