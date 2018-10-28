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
string str ;
int ara[MAX];
int main()
{
    cin>>str;
    for(int  i=0 ; i < str.size() -1 ; i++ ) {
        if( str[i] != str[i+1]) ara[i] = 1;
    }
    if( str[str.size()-1] =='a') ara[str.size()-1] = 1;
    for(int i =0 ; i < str.size() ; i++ ) {
        cout<<ara[i]<<" ";
    }
    cout<<endl;
    return 0;
}
