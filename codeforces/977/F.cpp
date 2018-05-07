#include <bits/stdc++.h>
#define ll          long long int
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
map<int,int>dp;
int n , ara[MAX] , ans ,val;
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    for(int i =0 ; i < n ; i++ ) {

        dp[ara[i]] =max( dp[ara[i]] , dp[ara[i]-1] + 1);
        if( ans < dp[ara[i]]) {
            ans = dp[ara[i]];
            val = ara[i];
        }
    }
    cout<<ans<<endl;
    vector<int>v;
    for(int i = n -1 ; i >=0 ; i-- ) {

        if( val == ara[i]) {
            v.push_back(i+1);
            val--;
        }
    }
    reverse( v.begin() , v.end());
    for(int i =0 ; i < v.size() ; i++ )
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
