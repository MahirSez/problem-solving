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
int n, ara[3];
bool mark[3];
string str;

int main()
{
    cin>>n>>str;
    for(int i =0 ; i < n ;i++ )
        if( str[i] == 'R') ara[0]++;
        else if( str[i] == 'G') ara[1]++;
        else ara[2]++;

    int cnt = (ara[0] !=0 ) + (ara[1] != 0 ) + (ara[2] != 0 );

    if( cnt == 3) {
        cout<<"BGR"<<endl;
        return 0;
    }
    if( cnt == 1 ) {

        if( ara[0] ) cout<<"R"<<endl;
        else if( ara[1] ) cout<<"G"<<endl;
        else if( ara[2] ) cout<<"B"<<endl;
        return 0;
    }
    string ans = "";
    if( ara[0] + ara[1] + ara[2] == 2) {

        if( ara[2]==0 ) ans+= "B";
        if( ara[1] ==0) ans+= "G";
        if( ara[0] ==0) ans+= "R";
        cout<<ans<<endl;
        return 0;
    }
    cnt = (ara[0] == 1) + (ara[1] == 1) + (ara[2] == 1);
    if( cnt ) {

        if( ara[2] ==1 || ara[2]==0 ) ans+= "B";
        if( ara[1] ==1 || ara[1]==0 ) ans+= "G";
        if( ara[0] ==1 || ara[0]==0 ) ans+= "R";
        cout<<ans<<endl;
        return 0;
    }
    else cout<<"BGR"<<endl;
    return 0;
}
