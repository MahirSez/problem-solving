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
int n , m ,ans[200];
struct info {
    int s , d , c , id;
} ara[1000];

bool comp(const info& in1 , const info& in2) {
    return in1.d < in2.d;
}

int main()
{
    cin>>n>>m;
    bool flg = true ;
    int cnt = m;
    for(int i =1 ; i <= m ;i++ ) {
        cin>>ara[i].s>>ara[i].d>>ara[i].c;
        if( ara[i].d - ara[i].s < ara[i].c) flg = false;
        cnt += ara[i].c;
        ara[i].id = i;
        ans[ara[i].d] = m+1;
    }
    if( cnt > n || !flg ) {
        cout<<-1<<endl;
        return 0;
    }
    sort( ara +1, ara + m + 1 , comp);
    for(int i = 1 ; i <= m ; i++ )  {
        int cnt = ara[i].c;
        for(int j = ara[i].s ; j < ara[i].d && cnt ; j++ ) {
            if( ans[j] == 0) {
                ans[j] = ara[i].id;
                cnt--;
            }
        }
        if( cnt ) {
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i = 1 ; i<= n ; i++ ) {
            cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
