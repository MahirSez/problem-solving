#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define ppi     	pair<pii,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n  , x[MAX] , y[MAX];
map<pii,ll>mp ;

set<ppi >s;


ppi get(int i , int j) {

    int yy = y[i] - y[j];
    int xx = x[i] - x[j];
    int c = y[i] * x[j] - y[j] * x[i];

    int gcd = __gcd(xx, yy);
    gcd = __gcd(gcd , c);

    yy/=gcd;
    xx/=gcd;
    c/=gcd;

    return {{xx,yy} , c};
}


int main()
{
	fastRead;
	cin>>n;
	for(int i =0 ; i < n ; i++ ) cin>>x[i]>>y[i];

    for(int i =0 ; i < n ; i++ ) {
		for(int j = i + 1 ; j < n ; j++ ) {

            ppi line = get(i , j);

            s.insert(line);
		}
    }
    ll lines = s.size();
//    cout<<lines<<endl;

    for(auto x : s) {
        int xx = x.uu.uu;
		int yy = x.uu.vv;
		int gcd = __gcd(xx , yy);

        mp[{xx/gcd,yy/gcd}]++;
    }

    ll ans = lines*(lines-1)/2;


    for(auto x : mp) {
        ans -= (x.vv)*(x.vv-1)/2;
    }
	cout<<ans<<endl;
	return 0;

}

