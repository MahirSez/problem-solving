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
using namespace std;
int x,y,n, cnt1, cnt2;
int main()
{
    cin>>n;
    while( n--) {
        cin>>x>>y;
        if( x>0) cnt1++;
        else cnt2++;
    }

    if( cnt1<=1 || cnt2<=1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
