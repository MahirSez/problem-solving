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
int n , m , ara[3000][3000] , stor[3000];
string str;
int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i <n ; i++ ) {
        cin>>str;
        for(int j =0 ; j < m ; j++ ) {
            if( str[j] == '1') {
                ara[i][j] = 1;
                stor[j]++;
            }
        }
    }
//    for(int i =0 ; i < m ;i++ ) cout<<stor[i]<<" ";
//    cout<<endl;
    for(int i =0 ; i < n ; i++) {
        bool ok = true;
        for(int j =0 ; j < m ;j++ ) {
            if( stor[j] == 1 && ara[i][j] == 1 ) {
                ok = false;
                break;
            }
        }
        if( ok ) {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
