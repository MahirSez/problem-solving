#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int main()
{
    fastRead;
    int n ;
    cin>>n;
    while( n-- ) {
		int sz;
		cin>>sz;
        string str;
        cin>>str;

		int id = -1;
        for(int i =0 ; i < sz; i++ ) {

            if( str[i] == '8') {
				id = i;
				break;
            }
        }
		if( id == -1)  {
			cout<<"NO\n";
			continue;
		}
        int cnt = 0;
        for(int i = id ; i < sz ; i++ ) {
            cnt++;
        }
        if( cnt >= 11) cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}
