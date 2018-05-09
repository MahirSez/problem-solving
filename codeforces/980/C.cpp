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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , k ,tmp, key;
int taken[300] , ans[300];
int main()
{
    fastRead;
    cin>>n>>k;
    for(int i =0 ; i < n ; i++ ) {

        cin>>tmp;
        if( taken[tmp] ==1 ) {
            cout<<ans[tmp]<<" ";
            continue;
        }
        key = tmp;
        for(int j = 0 ; j < k-1 && key > 0 && taken[key-1] ==0 ;j++) {
            key--;
        }
        if( key == 0 || taken[key-1] == 0 || ans[key-1] + k-1 < tmp ){

            for(int j = key ; j <=tmp ; j++ ) {
                ans[j] = key;
                taken[j] = 1;
            }
        }
        else {

            for(int j = key ; j <= tmp ; j++ ) {
                ans[j] = ans[key-1];
                taken[j] = 1;
            }
        }
        cout<<ans[tmp]<<" ";
    }
    cout<<endl;
    return 0;
}
