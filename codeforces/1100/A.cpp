#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , k;
int ara[2000];
int ans  ;
int main()
{
    fastRead;
    cin>>n>>k;
    ans = -1;
    int e = 0 , s = 0;

    for(int i =1 ; i  <= n; i++ ) {
        cin>>ara[i] ;
        if( ara[i] == -1) s++;
        else e++;
    }

    for(int i =1 ; i<= n ; i++ ) {

        int tmpE = e;
        int tmpS = s;

        int b = i;

        for(int j = 1 ; j <= n ; j++ ) {

            if( (j - b)%k == 0) {
                if( ara[j] == -1) tmpS--;
                else tmpE--;
            }
        }

        ans = max(ans , abs(tmpE - tmpS));
    }

    cout<<ans<<endl;
    return 0;
}
