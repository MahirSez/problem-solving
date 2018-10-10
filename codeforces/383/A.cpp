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
int n;
int ara[MAX];
ll zero , one , prev;
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i];
        if( ara[i] ==0 ) zero++;
        else one++;
    }
    ll mx1 = 0;
    for(int i = 0 ; i < n ; i++ ) {
        if( ara[i] == 1) mx1 += zero;
        else zero--;
    }
    ll mx2 = 0;
    for(int i = n-1 ; i>= 0; i--) {
        if(ara[i] ==0 ) mx2 += one;
        else one--;
    }
    cout<<min( mx1 , mx2)<<endl;
    return 0;
}
