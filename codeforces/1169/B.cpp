#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define ppi         pair<pii,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m , x[MAX] , y[MAX];

int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < m ; i++ ) {
        cin>>x[i]>>y[i];
    }

    int a , b , c;
    a = x[0];

    bool ok ;

    for(int  i =0 ; i < m ; i++ ) {
        if( x[i] != a && y[i] != a ) {
            b = x[i];
            c = y[i];
            break;
        }
    }


    ok = true;

    for(int i =0 ; i < m ; i++ ) {
        if( x[i]!= a && y[i] != a && x[i] != b && y[i] != b) {
            ok = false;
            break;
        }
    }
    if( ok  ) {
        cout<<"YES"<<endl;
        return 0;
    }
    ok = true;

    b = c;

    for(int i =0 ; i < m ; i++ ) {
        if( x[i]!= a && y[i] != a && x[i] != b && y[i] != b) {
            ok = false;
            break;
        }
    }
    if( ok  ) {
        cout<<"YES"<<endl;
        return 0;
    }

    ok = true;
    a = y[0];

    for(int  i =0 ; i < m ; i++ ) {
        if( x[i] != a && y[i] != a ) {
            b = x[i];
            c = y[i];
            break;
        }
    }


    ok = true;

    for(int i =0 ; i < m ; i++ ) {
        if( x[i]!= a && y[i] != a && x[i] != b && y[i] != b) {
            ok = false;
            break;
        }
    }
    if( ok  ) {
        cout<<"YES"<<endl;
        return 0;
    }
    ok = true;

    b = c;

    for(int i =0 ; i < m ; i++ ) {
        if( x[i]!= a && y[i] != a && x[i] != b && y[i] != b) {
            ok = false;
            break;
        }
    }
    if( ok  ) {
        cout<<"YES"<<endl;
        return 0;
    }

    cout<<"NO"<<endl;
    return 0;

}
