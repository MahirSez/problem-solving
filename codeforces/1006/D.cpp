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
string s1 , s2;
char a , b , c , d;
int main()
{
    cin>>n>>s1>>s2;
    int ans = 0;
    for(int i = 0 , j = n-1 ; i < j ; i++ , j--) {
        a = s1[i] , b = s1[j];
        c = s2[i] , d = s2[j];
        memset(ara , 0 , sizeof ara);
        ara[a-'a']++;
        ara[b-'a']++;
        ara[c-'a']++;
        ara[d-'a']++;
        int two = 0;
        int cnt =0;
        for(int j =0 ; j < 26 ; j++ ) {
            if(ara[j]) cnt++;
            if( ara[j] ==2 ) two++;
        }
        if( cnt == 4 ) ans += 2;
        else if( cnt == 3 ) {
            if(a==d || c==b) ans++;
            else if(c==d || a==c || b==d) ans++;
            else ans+=2;
        }
        else if( cnt==2) {
            if( two != 2) ans++;
        }
//        cout<<i<<" "<<cnt<<" "<<ans<<endl;
    }
//    cout<<ans<<endl;
    if( n&1 && s1[n/2] != s2[n/2]) ans++;
    cout<<ans<<endl;
    return 0;
}
