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
int n , vis[500][500][500];
double dp[500][500][500];
int one , two , three;


double solve(int uno , int dos , int tres) {

    int tot = uno + dos + tres;
    if( tot == 0 ) {
        return 0;
    }

    int &ret = vis[uno][dos][tres];
    if( ret != 0 ) return dp[uno][dos][tres];
    ret = 1;

    double ans = n*1.00/tot -1;
    if( uno ) ans += uno*1.00/tot * (1 + solve(uno -1 , dos , tres) ) ;
    if( dos ) ans += dos*1.00/tot * (1 + solve(uno +1 , dos-1 , tres));
    if( tres) ans += tres*1.00/tot * (1 + solve(uno , dos + 1 , tres-1));

    return dp[uno][dos][tres] =ans;

}


int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        int tmp;
        cin>>tmp;
        if( tmp == 1) one++;
        else if( tmp == 2) two++;
        else three++;
    }

    cout<<setprecision(12)<<fixed<<solve(one , two , three)<<endl;
    return 0;
}
