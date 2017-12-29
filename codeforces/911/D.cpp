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
int n , tmp , ans;
int ara[MAX];
int main()
{
    cin>>n;
    for( int  i =1 ; i <= n  ; i++ ) {

        cin>>ara[i];
    }

    for( int  i =1 ; i <= n ; i++) {

        for( int j = i +1 ; j <=  n ; j++) {

            if( ara[i] > ara[j]) ans++;
        }
    }

    int m;
    cin>>m;

    while( m -- ) {

        int u , v;
        cin>>u>>v;

        tmp = ( (v-u+1));
        tmp = tmp *(tmp-1) /2;
        tmp %=2;

        ans ^= tmp;

        if( ans %2 ) cout<<"odd"<<endl;
        else cout<<"even"<<endl;
    }
    return 0;
}
