#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
string str;
int p  , l;
int main()
{
    cin>>str;
    for(int i =0 ; i < str.size() ;i++ ) {

        if(str[i] == 'o') p++;
        else l++;
    }
    if( l == 0 || p == 0 || l%p == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
