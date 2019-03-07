#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
map<pii, int>mp;
int cnt , tmp;
int n , a[MAX] , b[MAX];
int main()
{
    fastRead;
    // cout<<__gcd(0,-2)<<endl;
    // cout<<__gcd(2,-2)<<endl;

    // cout<<__gcd(-2,-2)<<endl;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>a[i];
    for(int i =0 ; i < n ; i++ ) cin>>b[i];

    for(int i =0 ; i < n ; i++ ) {
        
        if( a[i] == 0 && b[i] == 0) {
            tmp++;
            continue;
        }

        if( a[i] ==0 ) {
            continue;
        }

        if( b[i] == 0 ) {
            cnt++;
            continue;
        }
        


        int tmp = __gcd(a[i] , b[i]);

        a[i] /=tmp;
        b[i] /=tmp;
        // cout<<a[i]<<" "<<b[i]<<endl;

        mp[{a[i] , b[i]}]++;
    }
    int ans =0;
    for(auto x : mp) {

        ans = max(ans , x.vv);
    }
    cout<<max(ans,cnt) + tmp<<endl;
}