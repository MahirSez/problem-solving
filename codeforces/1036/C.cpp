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
int t , dp[20][2][5];
vector<int>v;

ll solve(int id , int isSmall , int cnt) {

    if( cnt > 3) return 0;
    if( id == v.size() ) return 1;

    int &ret = dp[id][isSmall][cnt];
    if(ret != -1 )return ret;

    ret = 0;
    int till = 9;
    if( !isSmall ) till = v[id];

    for(int i =0 ; i <= till ; i++ ) {

        if( isSmall ||  i < till ) {
            ret += solve(id+1 , 1 , cnt + (i!=0) );
        }
        else ret += solve(id+1 , 0 , cnt + (i!=0));
    }
    return ret;
}

ll get(ll tmp) {
    v.clear();
    while (tmp) {
        v.push_back(tmp%10);
        tmp/=10;
    }
    reverse(v.begin() , v.end());
    return solve( 0 , 0 , 0);
}


int main()
{
    fastRead;
    cin>>t;
    while( t-- ) {
        ll frm ,to;
        cin>>frm>>to;
        memset(dp , -1 , sizeof dp);
        ll ans1 = get(frm-1);
        memset(dp , -1 , sizeof dp);
        ll ans2 = get(to);
        cout<<ans2 - ans1<<'\n';
    }
    return 0;
}
