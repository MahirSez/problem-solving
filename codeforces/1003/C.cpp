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
int n , k , ara[MAX] , sum[MAX];
int main()
{
    fastRead;
    cin>>n>>k;
    for(int i =1  ; i <=  n ; i++ ) cin>>ara[i];
    for(int i =1 ; i<= n  ; i++ ) {
        sum[i] = sum[i-1] + ara[i];
    }
    double mx = 0;
    for(int i =1 ; i  <=n ; i++ ) {

        for(int j = i + k -1 ; j <= n ;j++ ) {

            double tot = sum[j] - sum[i-1];
            double cnt = 1.00*(j - i + 1);
            mx = max( mx , tot/cnt);
        }
    }
    cout<<setprecision(10)<<fixed<<mx<<endl;
    return 0;
}
