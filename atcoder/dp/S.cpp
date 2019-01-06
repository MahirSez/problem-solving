#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string str;
vector<int>v;
ll dp[20000][2][200];
int d , n;

void process() {

    for(int i =0 ; i < str.size() ; i++ ) {

        v.push_back(str[i]-'0');
    }

    n = v.size();
//    for(int i =0 ; i < v.size() ; i++ ) {
//        cout<<v[i]<<" ";
//    }

}

ll solve(int id , int isSmall , int rem) {

    if( id== n ) {
        if( rem ==0 ) return 1;
        return 0;
    }

    ll &ret = dp[id][isSmall][rem];
    if( ret != -1) return ret;

    ret = 0;

    int till ;
    if( isSmall) till = 9;
    else till = v[id];

    for(int i =0 ; i <= till ; i++ ) {

        if( isSmall || i < till) {

            ret = (ret + solve(id +1 , 1 , (rem + i)%d ) %MOD) %MOD;
        }
        else ret = (ret + solve(id+1 , 0 , (rem+ i)%d ) %MOD) %MOD;
    }

    return ret;

}


int main()
{
    cin>>str>>d;
    process();
    memset(dp , - 1, sizeof dp);
    cout<<(solve(0 , 0 , 0) + MOD-1)%MOD<<endl;
    return 0;

}
