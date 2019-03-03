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
int n , ara[1003];
int taken[MAX] ;
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i];
    }
    int ans = 0;

    for(int i =0 ; i < n ; i++ ) {
        for(int j = i+ 1 ; j < n ; j++ ) {
            taken[ara[i] + ara[j]]++;
            ans = max(ans , taken[ara[i] + ara[j]]);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}