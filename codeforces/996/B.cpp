#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<ll,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n;
ll ara[MAX] ;
pii str[MAX];
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    for(int i =0 ; i<n ; i++ ) {
        ara[i]-=i;
        if( ara[i] <= 0 ) {
            cout<<i+1<<endl;
            return 0;
        }
        str[i] = {ceil(ara[i]*1.00/n) , i+1};
    }
    sort( str, str + n);
    cout<<str[0].vv<<endl;
    return 0;
}
