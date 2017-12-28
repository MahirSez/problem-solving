#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9 +
#define EPS		1e-8
#define MAX		1000006
using namespace std;
int n ,ara[MAX];
vector<int>v;
int main()
{
    cin>>n;
    int mn;
    cin>>mn;
    ara[0] = mn;
    for( int  i =1 ; i < n ; i++) {

        cin>>ara[i];
        mn  = min( ara[i] , mn);
    }


//    cout<<v.size()<<endl;
    for( int  i =0 ; i < n ; i++) {

        if( mn == ara[i] ) v.push_back(i);
    }

    int diff = abs(v[1] - v[0]);

    for( int  i =0 ; i < v.size() -1; i++ ) {

        diff = min( diff , abs(v[i] - v[i+1]) );
    }
    cout<<diff<<endl;
    return 0;
}
