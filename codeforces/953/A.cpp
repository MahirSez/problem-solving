#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS     1e-8
#define MAX     1000006
#define MOD     1000000007
using namespace std;
ll l , r ,  tmp ,a ,b;
vector<ll>two , three,six;
int main()
{
    cin>>l>>r;
    a = 2;
    b=3;
    while( true) {

        two.push_back(a);
        a *= 2;
        if( a > r) break;
    }

    while( true) {

        three.push_back(b);
        b *= 3;
        if( b > r ) break;
    }

    for(int  i =0; i < two.size() ; i++ ) {

        for(int  j =0 ;  j < three.size() ; j++ ) {

            ll tmp = two[i] * three[j];

            if( tmp >= l && tmp <= r)
                six.push_back(tmp);
        }
    }

    if( l == 1) six.push_back(1);

    for(int  i = 0 ; i < three.size() ; i++ ) {

        if( three[i] >= l && three[i] <= r)
            six.push_back(three[i]);
    }
    for(int  i =0 ; i < two.size() ; i++ ) {

        if( two[i] >= l && two[i]<=r)
            six.push_back(two[i]);
    }
    //cout<<two.size() <<" "<<three.size() <<" "<<six.size()<<endl;
    cout<<six.size() <<endl;
    return 0;
}
