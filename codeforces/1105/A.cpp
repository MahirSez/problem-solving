#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , ara[20000];
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i];
    }
    int ans = INF;
    int id = -1;
    for(int i =1 ; i<= 200 ; i++) {

        int tgt1 = i , tgt2 = i-1 , tgt3 = i+1 ;
        int tot = 0;
        for(int j =0 ; j < n ; j++ ) {

            int sum = abs(ara[j] - tgt1);
            sum = min( sum , abs(ara[j] - tgt2));
            sum = min( sum , abs(ara[j] - tgt3));
            tot += sum;
        }
        if( tot < ans) {
            id = i;
            ans = tot;
        }
    }
    cout<<id<<" "<<ans<<endl;
    return 0;
}
