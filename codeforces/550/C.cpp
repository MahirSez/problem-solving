#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS     1e-8
#define MAX     1000006
#define MOD     1000000007
using namespace std;
string str;
int dp[1000][10][5];

int ok(int id , int mod, int taken) {

    if( id == str.size() ) {

        if(mod==0 && taken) return 1;
        return 0;
    }
    int &ret = dp[id][mod][taken];

    if( ret!=-1 ) return ret;
    ret = 0;
    ret |= ok(id+1 , mod , taken);
    ret |= ok(id +1 , (mod* 10 + (str[id]-'0') ) % 8 , 1);
    return ret;
}


void print(int id ,int mod ,int taken) {
    if( id == str.size() ) return;

    if( ok(id +1 , mod, taken) )
         print(id+1 , mod , taken);
    else {
        cout<<str[id];
        print(id +1 , (mod*10 +(str[id]-'0') ) % 8, 1);
    }
}

int main()
{
    cin>>str;
    memset(dp , -1 , sizeof(dp));
    if( ok(0,0,0)) {
        cout<<"YES"<<endl;
        print(0,0,0);
        cout<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}
