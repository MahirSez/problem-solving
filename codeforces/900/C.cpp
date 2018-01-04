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
int n;
int ara[MAX];
int mx, sec , x;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for( int  i =0 ; i < n ; i++) {

        cin>>x;
        if( x > mx ) {
            ara[x] = 1;
            sec = mx;
            mx = x;
        }
        else if( x > sec ) {

            ara[mx]--;
            sec = x;
        }
    }
    int ans = 2;
    for( int  i =1 ; i<=n; i++ ) {

        if( ara[i] < ans) {
            x = i;
            ans = ara[i];
        }
    }
    cout<<x<<endl;
    return 0;
}
