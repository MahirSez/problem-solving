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
ll ara[MAX];
int n;
ll sum;
int main()
{
    fastRead;
    cin>>n;
    for(int i = 0 ; i < n ; i++ ) {
        cin>>ara[i];
        sum += ara[i];
    }
    sort(ara , ara+n);
    reverse(ara , ara + n);
    int m;
    cin>>m;
    while( m-- ) {
        int tmp;
        cin>>tmp;
        tmp--;
        cout<<sum-ara[tmp]<<'\n';
    }
    cout<<endl;
    return 0;

}