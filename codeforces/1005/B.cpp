#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int id1 , id2;
string s1 , s2;
int main()
{
    cin>>s1>>s2;
    reverse(s1.begin() ,s1.end());
    reverse(s2.begin() ,s2.end());
    int sz1 = s1.size();
    int sz2 = s2.size();
    int tot = sz1 + sz2;
    for(int i =0 ;i < min(sz1 , sz2) ; i++ ) {
        if( s1[i] != s2[i] ) break;
        else id1++;
    }
    cout<<tot - id1*2<<endl;
    return 0;
}
