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
string str;
int main()
{
    cin>>str;
    for( int  i=0 ,j = 0; i < str.size(); i++) {

        if(str[i] <= (char)('a' + j  ) ) {

            str[i] = (char)('a' +j);
            j++;
        }
        if( j ==26) {
            cout<<str<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
