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
int n , ara[30];
string str;
int main()
{
    int n;
    cin>>n;
    if( n== 1) {
        cout<<"Yes"<<endl;
        return 0;
    }
    cin>>str;
    for(int i =0 ; i < str.size() ; i++ ) {
        ara[str[i]-'a']++;
    }
    for(int i =0 ; i < 27 ; i++ ) {
        if( ara[i] >=2 ) {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
