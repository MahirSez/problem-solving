#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , k;
int ara[MAX];
int taken[10000];
int main()
{
    fastRead;
    cin>>n>>k;
    for(int i =0 ; i < n ; i++ ) {
        int tmp;
        cin>>tmp;
        tmp%=k;
        taken[tmp]++;
    }
    int ans =0;
    

    for(int i =1 ; i < k ; i++ ) {
        
        if( i == k-i ) ans += (taken[i]/2)*2;
        else ans += min(taken[i] , taken[k-i])*2;
        taken[i] = 0;
        taken[k-i] = 0;
    }
    ans += (taken[0]/2)*2;
    cout<<ans<<endl;
    return 0;
}