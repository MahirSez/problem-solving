#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pip 		pair<int,pii>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n;
string str;
int main()
{
    fastRead;
    cin>>n>>str;
    for(int i =0 ;i < n-1 ; i++) {
        if( str[i] > str[i+1]) {
            cout<<"YES"<<endl;
            cout<<i+1<<" "<<i+2<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;

}
