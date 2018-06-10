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
int ara[MAX], n , k;
int main()
{
    fastRead;
    cin>>n>>k;
    for(int i = 0 ; i < n ; i++ ) cin>>ara[i];
    sort(ara, ara + n);
    int cnt = n;
    for(int i =0 ; i < n-1 ;i++ ) {
        int id = upper_bound(ara , ara +n , ara[i] + k) -ara;
//        cout<<ara[i]<<" "<<ara[id-1]<<endl;
        if( ara[id-1] > ara[i]) cnt--;
    }
    cout<<cnt<<endl;
    return 0;
}
