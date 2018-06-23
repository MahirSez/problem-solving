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
int n ;
int tmp,  ara[10000];
int sum;
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i];
        sum += ara[i];
    }
    sort( ara , ara + n );
    int tgt = ceil(4.5*n);
    if( sum >= tgt) {
        cout<<0<<endl;
        return 0;
    }
    for(int i =0 ; i < n ;i++ ) {
        sum -= ara[i];
        sum += 5;
        if( sum >= tgt) {
            cout<<i+1<<endl;
            return 0;
        }
    }
    return 0;
}
