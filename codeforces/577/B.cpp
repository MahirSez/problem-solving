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
int n , m;
int dp[1003][1003][2] , ara[MAX];

bool ok(int id , int num , int taken) {
    if( id==n) {
        return (num==0 && taken);
    }
    int &ret = dp[id][num][taken];
    if(ret != -1) return ret;
    ret = ok( id+1 ,(num + ara[id])%m , 1) | ok(id+1,num,taken);
    return ret;
}

int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < n ; i++) cin>>ara[i];
    if( n >= m) {
        cout<<"YES"<<endl;
        return 0;
    }
    memset(dp , -1 , sizeof dp);
    if( ok(0,0,0) ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
