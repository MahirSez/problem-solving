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
ll n;

ll sum(ll tmp) {
    ll tot = 0;
    while( tmp ) {
        tot += tmp%10;
        tmp/=10;
    }
    return tot;
}

int main()
{
    cin>>n;
    ll tmp = n;
    int cnt = 0;
    while( tmp )  {
        tmp/=10;
        cnt++;
    }

    tmp = 0;
    cnt--;
    while(cnt--) {
        tmp = tmp *10 + 9;
    }
    cout<<sum(tmp) + sum(n - tmp)<<endl;
    return 0;
}
