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
ll n , m ;
string s1 , s2;
ll str[MAX][26];
int main()
{
    cin>>n>>m;
    cin>>s1>>s2;
    ll sz1 = s1.size();
    ll sz2 = s2.size();
    if( sz1 < sz2) {
        swap(s1,s2);
        swap(sz1 , sz2);
        swap(n,m);
    }

    if( sz1 % sz2==0) {
        ll cnt =0 ;
        for(int i =0 ; i < sz1 ; i++ ) {
            if( s1[i] != s2[i%sz2]) cnt++;
        }
        cout<<cnt * n<<endl;
        return 0;
    }

    ll gcd = __gcd(sz1 , sz2);
//    cout<<gcd<<endl;
    for(int i =0 ; i < sz1 ; i++ ) {
        str[ i%gcd ][ s1[i] - 'a' ]++;
    }
    ll ans = 0;

    for(int i =0 ; i < sz2 ; i++ ) {

        int tgt = s2[i] - 'a';
        for(int j =0 ; j < 26 ; j++ ) {
            if( tgt == j ) continue;
            ans += str[ i%gcd ][ j ];
        }
    }
    ll lcm = (sz1*sz2)/ gcd;
    ans *= (n*sz1/lcm);
//    ans *= ( (sz1*gcd)/m );
    cout<<ans<<endl;
    return 0;
}
