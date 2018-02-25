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
int n;
bool ara[MAX];
int main()
{
    cin>>n;
    int cnt = 0;
    for(int  i=0 ; i < n ; i++ ) {

        int tmp;
        cin>>tmp;
        if( tmp && ara[tmp] == false) {
            cnt++;
            ara[tmp] = 1;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
