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
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , ara[200] , pos , neg;
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i];
        if(ara[i] > 0 ) pos++;
        else if( ara[i] < 0) neg++;
    }

    int tgt = (n-1)/2+1;

    if( pos >= tgt) {
        cout<<1<<endl;
    }
    else if( neg >=tgt) {
        cout<<-1<<endl;
    }
    else cout<<0<<endl;
    return 0;
}