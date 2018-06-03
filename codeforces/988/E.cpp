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
string str;
map<int,int>mp;


int make(string tmp , int  a , int b) {
    if( mp[a] ==0 ) return INF;
    if( mp[b] ==0 ) return INF;
    if( a == b && mp[a] < 2  )  return INF;

    int cnt =0;
    for(int i = tmp.size() - 1 ; i >=0 ; i--) {
        if( (tmp[i]-'0') == b ) {
            for(int j = i; j < tmp.size() - 1; j++ ) {
                swap( tmp[j] , tmp[j+1]);
                cnt++;
            }
            break;
        }
    }
    for(int i = tmp.size() - 2 ; i >=0 ; i--) {
        if( (tmp[i]-'0') == a ) {

            for(int j = i; j < tmp.size() - 2; j++ ) {
                swap( tmp[j] , tmp[j+1]);
                cnt++;
            }
            break;
        }
    }
    int cntz = 0;
    for(int i =0 ; i < tmp.size()-2 ; i++ ) {
        if( tmp[i] == '0') cntz++;
        else break;
    }
    if( cntz && cntz == tmp.size() - 2) return INF;
    return cnt  + cntz;
}

int main()
{
    cin>>str;
    for(int i = 0 ; i < str.size() ; i++ ) mp[(str[i]-'0')]++;
    int ans = INF;
    ans = min( ans , make(str, 0 , 0));
    ans = min( ans , make(str , 2 , 5));
    ans = min( ans , make(str , 5 , 0));
    ans = min( ans , make(str , 7, 5));
    if( ans == INF ) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
