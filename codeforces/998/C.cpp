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
ll x , y , cnt;
int n;
string str;
int main()
{
    cin>>n>>x>>y;
    cin>>str;
    str += '*';
    bool started = 0;
    for(int i =0 ; i <=n ; i++ ) {
        if( str[i] == '0') {
            if( started ) continue;
            else {
                started = 1;
                cnt ++;
            }
        }
        else started = 0;
    }
    if( cnt == 0) {
        cout<<0<<endl;
        return 0;
    }
//    cout<<cnt<<endl;
    ll ans1 = cnt * y;
    ll ans2 = (cnt - 1 ) * x+ y;
    cout<<min(ans1 , ans2)<<endl;
    return 0;
}
