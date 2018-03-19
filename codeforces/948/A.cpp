#include <bits/stdc++.h>
#define ll			long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(nullptr);
using namespace std;
int n , m ;
int ara[1000][1000];
string str;

int test() {

    for(int  i =1; i<= n ; i++ ) {

        for(int j = 1; j <=m ; j++) {

            if( ara[i][j]  + ara[i-1][j] == 3  ) return -1;
            if( ara[i][j] + ara[i][j-1] == 3 ) return -1;
        }
    }
    return 0;
}

int main()
{
    cin>>n>>m;
    for(int  i= 1 ; i <= n ;i++) {

        cin>>str;
        for(int  j = 0 ; j < str.size() ; j++ ) {

            if( str[j] == 'S') ara[i][j+1] = 1;
            else if( str[j] == 'W') ara[i][j+1] = 2;
        }
    }

    int tmp = test();
    if( tmp == -1) {
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    for(int i = 1; i<= n ;i++ ) {
        for(int  j = 1 ;j<= m ;j++ ) {
            if( ara[i][j] == 0)
                cout<<"D";
            else if( ara[i][j] == 1)
                cout<<"S";
            else cout<<"W";

        }
        cout<<endl;
    }
    return 0;
}
