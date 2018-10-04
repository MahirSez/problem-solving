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
int n ;
string str;
int ara[20] , cnt , ans;
int main()
{
    fastRead;
    cin>>n>>str;
    for(int i =0 ; i < n ; i++ ) {
        ara[str[i] - '0']++;
    }
    cnt = ara[8];
    if( cnt ==0 ) {
        cout<<0<<endl;
        return 0;
    }


    for(int i =1 ;i <= cnt ; i++ ) {
        ans = max(ans , min(i , (n-i)/10 ) );
    }
    cout<<ans<<endl;
    return 0;
}
