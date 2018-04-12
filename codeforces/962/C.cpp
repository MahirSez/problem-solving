#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
string str;
int dp[(1<<10)+2] , n;

bool removed(int mask , int id) {
    return (mask & (1<<id));
}
int setBit(int mask , int pos) {

    return mask |=(1<<pos) ;
}

bool ok(int mask) {

//    cout<<mask<<" wewer"<<endl;
    int num = 0;

    for(int i =0 ; i < n ;i++ ) {

        if( !removed(mask ,i ) ) {
            if( str[i] == '0') return false;
            else break;
        }
    }

    for(int i =0 ; i < n ;i++ ) {

        if( !removed(mask,i) ) num = num*10 + (str[i]-'0');
    }
//    cout<<num<<" sdfsdf"<<endl;
    int rt = sqrt(num);
    return (rt *  rt == num);
}

int solve(int mask) {
//    cout<<mask<<" asdasd"<<" "<<(1<<n)-1<<endl;
    if( mask == ( (1<<n)-1) || ok(mask) ) return 0;

    int &ret = dp[mask];
    if( ret != -1 ) return ret;

    ret = INF;

    for(int  i= 0 ; i < n ;i++ ) {

        if( !removed(mask,i) ) {
            ret = min( ret , 1 + solve(setBit(mask , i) )) ;
        }
    }
    return ret;
}

int main()
{
    cin>>str;
    n =str.size() ;
    memset(dp , -1 , sizeof dp);
    int ans = solve(0);
    if( ans == n) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
