#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int n;
int main()
{
    fastRead;
    cin>>n;
    if(n < 6) cout<<-1<<endl;
    else {

        int tmp = n/2 - 1;

        for(int  i = 2 ; i <= n-tmp ; i++ )  {

            cout<<1<<" "<<i<<endl;
        }

        for(int i = n - tmp  + 1 ; i <= n; i++ )
            cout<<2<<" "<<i<<endl;
    }
    for(int i = 1 ; i< n ;i++ )
        cout<<i<<" "<<i+1<<endl;
    return 0;
}
