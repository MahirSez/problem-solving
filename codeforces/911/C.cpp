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
int ara[2000];
int main()
{
    int a, b , c;
    cin>>a>>b>>c;
    ara[a]++;
    ara[b]++;
    ara[c]++;

    if( ara[1] >= 1 || ara[2] >= 2 || ara[3] >= 3   ) {
        cout<<"YES"<<endl;
        return 0;
    }
    if( ara[2] == 1 && ara[4] ==2 ) {
        cout<<"YES"<<endl;
        return 0;
    }
    cout<<"NO"<<endl;
    return  0;
}
