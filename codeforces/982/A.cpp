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
int n;
string str;
int main()
{
    cin>>n>>str;
    for(int i =0 ; i < n-1 ; i++ ) {

        if( str[i] == '1' && str[i+1] == '1') {
            cout<<"No"<<endl;
            return 0;
        }
    }
    if( n==1 && str=="0") {
        cout<<"No"<<endl;
        return 0;
    }
    if( n >= 2) {
        if( str[0] == '0' && str[1] == '0' ) {
            cout<<"No"<<endl;
            return 0;
        }
        if( str[n-1] == '0' && str[n-2] == '0') {
            cout<<"No"<<endl;
            return 0;
        }
    }

    for(int i = 1 ; i < n-1 ; i++ ) {
        if( str[i-1] =='0' && str[i]=='0' && str[i+1] == '0') {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}
