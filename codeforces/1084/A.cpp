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
int n , ara[2000];
int main()
{
    fastRead;
    cin>>n;
    for(int i = 1 ; i<= n ; i++ ) cin>>ara[i];
    int ans = INF;
    for(int x = 1 ; x <= n ;x++ ) {
        int tmp =0;
        for(int i =1 ; i<=n ; i++ ) {
            tmp += (abs(x-i) + i-1 +x-1)*2 *ara[i]  ;
        }
        ans = min(tmp, ans);
    }
    cout<<ans<<endl;
    return 0;
}
