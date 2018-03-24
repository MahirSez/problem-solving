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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
string str;
int n  ,ans , tmp;
bool flg;
int main()
{
    cin>>n;
    cin>>str;
    flg = true;
    for(int i =0 ; i < n-1 ;i++) {

        if( str[i]==str[i+1] && str[i]!='?')
            flg = false;
    }
    if( flg == false) {
        cout<<"No"<<endl;
        return 0;
    }
    flg = false;
    for(int  i=0 ; i < n ; i++) {
        if( str[i] =='?') {
            flg = true;
            tmp++;
        }
    }
    if( flg == false) {
        cout<<"No"<<endl;
        return 0;
    }
    if( str[0] =='?' || str[n-1]=='?') {
        cout<<"Yes"<<endl;
        return 0;
    }

    flg = false;
    for(int i = 1; i < n- 1 ; i++  ) {

        if( str[i] == '?' && str[i-1] == str[i+1])
            flg = true;
        else if( str[i]== str[i+1] && str[i]=='?' )
            flg = true;
    }
    if( flg ) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
