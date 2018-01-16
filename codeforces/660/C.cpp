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
int n , k , l=-1 , r =-1, j=-1 , mx, zero , ara[MAX];
int main()
{
    cin>>n>>k;
    for( int i =0 ; i  < n ; i++ ){
        cin>>ara[i];
    }

    for( int  i =0 ; i < n  ;i ++) {
        while( j< n && zero <= k ) {

            if( ara[j+1] == 0) zero++;
            j++;
        }

        if( j-i > mx) {
            mx = j - i  ;
            l = i;
            r = j-1;
        }
        if( ara[i] == 0) zero--;
    }
    cout<<mx<<endl;
    for( int  i= 0; i < n ; i++ ) {

        if( i >=l && i<=r) cout<<1<<" ";
        else cout<<ara[i]<<" ";
    }
    return 0;
}
