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
string str1 , str2;
int main()
{
    cin>>str1>>str2;
    string ans = "";
    ans += str1[0];

    for( int i = 1; i < str1.size() && str2[0] > str1[i]; i++)
        ans += str1[i];

    ans+= str2[0];
    cout<<ans<<endl;
}
