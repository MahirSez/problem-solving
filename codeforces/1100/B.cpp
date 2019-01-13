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
int n , m;
int ara[MAX];
int cnt;
int main()
{
    fastRead;
    cin>>n>>m;
    for(int i = 0 ; i < m ; i++ ) {

        int tmp;
        cin>>tmp;
        if( ara[tmp] == 0) cnt++;
        ara[tmp]++;
        if( cnt == n ) {
            cout<<1;
            cnt = 0;
            for(int j = 1 ; j<= n ; j++ ) {
                ara[j]--;
                if( ara[j] > 0) cnt++;
            }
        }
        else cout<<0;
    }
    cout<<'\n';
    return 0;
}
