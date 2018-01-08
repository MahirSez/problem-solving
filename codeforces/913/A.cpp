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
int n, m ;
int main()
{
    cin>>n>>m;
    if( n >=27) {
        cout<<m<<endl;
        return 0;
    }
    int mod = 1<<n;
    cout<<m%mod<<endl;
    return 0;

}
