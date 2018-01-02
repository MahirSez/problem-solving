#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,string>
#define INF     1e10
#define EPS		1e-8
#define MAX		1000006
using namespace std;
ll ans ;
int mr , mb , lr , lg , lb , tmp, n;
string str;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for( int i =0 ; i < n ;i++) {

        cin>>tmp>>str;
        if( str == "R") {

            if( lr == 0) lr = tmp;
            mr = max( mr , tmp - lr);
            ans += tmp - lr;
            lr = tmp;
        }
        else if( str == "B") {

            if( lb == 0) lb = tmp;
            mb = max(mb , tmp - lb);
            ans += tmp - lb;
            lb = tmp;
        }
        else {

            if( lr == 0) lr = tmp;
            if( lb == 0) lb = tmp;
            if( lg == 0) lg = tmp;

            ans += (tmp - lg);
            ans += (tmp - lb);
            ans += (tmp - lr);

            mb = max( mb , tmp - lb);
            mr = max( mr , tmp - lr);

            if( tmp - lg )
                if( mb + mr > tmp - lg) ans -= (mb + mr);
                else ans -= (tmp - lg);
            mb = 0;
            mr = 0;
            lg = tmp;
            lr = tmp;
            lb = tmp;
        }
    }

    cout<<ans<<endl;
    return 0;
}
