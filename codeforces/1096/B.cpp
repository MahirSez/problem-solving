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
#define MOD     	998244353
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n;
string str;

ll l , r;
int main()
{
    cin>>n>>str;
    int cnt = 0;
    for(int i =0; i < n ; i++) {
        if( str[i] == str[0]) cnt++;
        else break;
    }
    l = cnt;

    cnt = 0;
    for(int i =n-1 ; i>=0 ; i--) {
        if( str[i] == str[n-1]) cnt++;
        else break;
    }
    r = cnt;

    if( str[0] == str[n-1]) {
        l++;
        r++;
        cout<<(l*r)%MOD<<endl;
        return 0;
    }

    cout<<(l + r+1)%MOD<<endl;
    return 0;
}
