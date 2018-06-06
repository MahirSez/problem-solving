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
int n ,ans[5005][5005], dp[5005][5005] ;
string str;

int ok(int l , int r) {

    if(l >= r) return 1;
    if( str[l] != str[r]) return 0;

    int &ret = dp[l][r];
    if( ret != -1 ) return ret;
    ret = ok(l+1 , r-1);
    return ret;
}

int solve(int frm ,int  to) {

    if( frm > to )  return 0;

    int &ret = ans[frm][to];
    if( ret != -1 ) return ret;
    ret = ok(frm , to) ;
    ret += solve(frm+1 , to) + solve(frm , to-1) - solve(frm+1 , to-1) ;
    return ret;
}


int main()
{
    fastRead;
    cin>>str;
    memset(dp , -1 , sizeof dp);
    memset(ans , -1 , sizeof ans);

    cin>>n;
    while( n-- ) {
        int frm , to;
        cin>>frm>>to;
        frm--, to--;
        cout<<solve(frm , to)<<"\n";
    }
    return 0;
}
