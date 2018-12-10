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
string str;
vector<ll>ara;
ll dp[MAX];
int n;

ll solve(int id) {
    if( id == n ) return 0;
    ll &ret = dp[id];
    if( ret != -1) return ret;

    ll tmp = solve(id+1)%MOD;

    ret = ( (ara[id] *(1 + tmp ) )%MOD + tmp)%MOD;
    return ret;

}
int main()
{
    cin>>str;
    ll cnt = 0;

    for(int i =0 ; i < str.size() ; i++ ) {
        if( str[i] == 'b') {
            if( cnt ) ara.push_back(cnt);
            cnt = 0;
        }
        else if( str[i] =='a') cnt++;
    }
    if(cnt) ara.push_back(cnt);
    memset(dp , -1 , sizeof dp);
    n = ara.size();
    cout<<solve(0)<<endl;
    return 0;
}
