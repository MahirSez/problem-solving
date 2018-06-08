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
#define MAX     	200005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll r , g , h , dp[MAX] ,ans[MAX],sum;

int tot(int x) {
    return (x *(x+1))/2;
}
void print() {
    for(int i = 0 ;i<= r ; i++ ) cout<<ans[i]<<" ";
    cout<<endl;
}
int main()
{
    cin>>r>>g;
    for(int i = 1 ; (i*(i+1)) <= (2*(r+g)) ;i++)  {
        h = i;
    }
    if( g == 0 ) swap(r,g);
    ans[0] =1;
    if( r ) ans[1] = 1;
    for(int i = 2 ; i<=h ; i++ ) {
        memset(dp ,0 ,sizeof dp);
//        cout<<i<<endl;
        //4print();
        for(int j = 0 ; j <= r ; j++ ) {

            if( tot(i) > j + g) continue;
            if( j>=i ) dp[j] = ans[j-i];
            dp[j] = (dp[j] + ans[j]) %MOD;
        }
        for(int j = 0 ; j <= r ; j++ ) {
            ans[j] = dp[j];
        }
    }
    for(int i =0 ; i<= r ; i++ ) sum = (sum + ans[i] )%MOD;
    cout<<sum<<endl;
    return 0;
}
