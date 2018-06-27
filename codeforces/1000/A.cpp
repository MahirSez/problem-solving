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
string a[1000] , b[1000];
int main()
{
    fastRead;
    cin>>n;
    for(int  i=0 ; i < n ; i++ ) cin>>a[i];
    for(int i =0 ; i < n ; i++) cin>>b[i];
    int ans = 0;
    for(int i =0 ; i < n ; i++ ) {
        bool done = false;
        for(int j =0 ; j < n ; j++ ) {
            if( a[i] == b[j]) {
                b[j] = "";
                done = true;
                break;
            }
        }
        if( !done) ans ++;
    }
    cout<<ans<<endl;
    return 0;
}
