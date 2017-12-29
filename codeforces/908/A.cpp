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
string str;
int main()
{
    cin>>str;
    int cnt = 0;
    for( int  i =0 ; i < str.size(); i++ ){

        if( str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            cnt++;
        else if( isdigit(str[i]) && (str[i]-'0') %2 ) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
