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
vector<int>sqr;
vector<int>non;
ll cnt , ans, x;

bool ok(int tmp) {

    int root = sqrt(tmp);
    return ( root * root == tmp);
}

int main()
{
    cin>>n;
    for( int  i =0 ; i < n ; i++) {
        cin>>x;
        if( ok(x) ) sqr.push_back(x);
        else non.push_back(x);
    }
    if( sqr.size() == non.size()) {
        cout<<0<<endl;
        return 0;
    }

    if( sqr.size() > non.size() ) {

        sort( sqr.rbegin() , sqr.rend() );
        for( int  i =0 ; i <(sqr.size() - non.size())/2 ; i++ ) {

            if( sqr[i] == 0) ans++;
            ans++;
        }
        cout<<ans<<endl;
        return 0;
    }
    vector<int>str;
    for( int i =0 ; i < non.size() ; i++ ) {

        int tmp = non[i];
        int case1 = sqrt(tmp);
        int case2 =  case1 +1;
//        cout<<tmp<<" "<<case1<<" "<<case2<<endl;
        str.push_back( min(  tmp -  case1 * case1 , case2*case2 - tmp ) );
//        cout<<str[i]<<" ";
    }
//    cout<<endl;
    sort(str.begin() , str.end() );

    for( int  i =0 ; i < (non.size() - sqr.size() )/ 2 ; i++) {
        ans += str[i];
    }
    cout<<ans<<endl;
    return 0;
}
