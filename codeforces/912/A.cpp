#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS		1e-8
#define MAX		1000006
#define MOD		1000000007
using namespace std;
ll Y ,B , yt , bt , gt;
int main()
{
    cin>>Y>>B>>yt>>gt>>bt;
    yt *=2;
    bt *=3;
    ll ans = 0;

    if(Y >= yt ) Y-=yt;
    else {
        ans +=( yt - Y);
        Y  =0;
    }

    if( B >= bt ) B-=bt;
    else  {
         ans += (bt - B);
         B = 0;
    }

    ll mn = min( Y, B);

    if( mn >= gt ) cout<<ans<<endl;
    else {
        Y -= mn;
        B -= mn;
        gt -= mn;

        ans += max( ( gt - Y), (ll)0);
        ans += max( ( gt - B), (ll)0);
        cout<<ans<<endl;
    }
    return 0;
}
