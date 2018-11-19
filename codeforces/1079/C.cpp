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
int n , ara[MAX] , ans[MAX], dp[MAX][6];

int solve(int id , int last) {

    if( id == n ) return 1;

    int &ret = dp[id][last];
    if( ret != -1) return ret;

    ret = 0;

    if( ara[id-1] > ara[id] ) {
        for(int i = last - 1; i >=1 ; i--) {
            if( solve(id+1 , i)  ) {
                ans[id] = i;
                return  ret =1;
            }
        }
    }
    if( ara[id-1] < ara[id]) {
        for(int i = last + 1; i <=5 ; i++) {
            if( solve(id+1 , i)  ) {
                ans[id] = i;
                return  ret =1;
            }
        }
    }
    if( ara[id-1] == ara[id]) {
        for(int i =1 ; i<=5 ;i++) {
            if( i == last) continue;
            if( solve(id+1, i )) {
                ans[id] = i;
                return ret = 1;
            }
        }
    }
    return ret;
}


int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    memset(dp , -1 , sizeof dp);
    bool ok = false;
    for(int i = 1 ; i<=5 ; i++ ) {

        ans[0] = i;
        if(solve(1 , i)) {
            ok = true;
            break;
        }
    }
    if( ok ) {

        for(int i = 0; i < n ; i++ ) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    cout<<-1<<endl;
    return 0;
}
