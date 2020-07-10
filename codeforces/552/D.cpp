#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0);cin.tie(0);
#define pii pair<int,int>
#define ppi pair<pii,int>
#define uu first
#define vv second
#define ll long long int
using namespace std;
const int N = 2002;
map<int, int>rec;

int x[N], y[N];
map<ppi, int> mp;

void change(int &x,int  &y, int &z) {

	int gcd = __gcd(abs(x) , abs(y));
    gcd = __gcd(gcd, abs(z));

	x /= gcd;
	y /= gcd;
    z /= gcd;

    if(x  < 0 ) {
        x *= -1;
        y *= -1;
        z *= -1;
    }
    else if( x == 0 &&  y < 0) {
        y *= -1;
        z *= -1;
    }
    else if(x== 0 && y == 0 && z < 0) z *=-1;
}

ll nc3(ll n) {

	return n*(n-1)*(n-2) / 6;

}
int main()
{
	fastio;
	for(int i =1 ; i < N ; i++ ) {
		rec[i * (i-1)] = i;
	}
	int n;
	cin>>n;
	for(int i=1 ; i <=n ; i++ ) cin>>x[i]>>y[i];

	for(int i =1 ; i <=n ; i++ ) {
		for(int j =1 ; j <=n ; j++ ) {
			if( i == j ) continue;
			int x1 = x[i], x2 = x[j];
			int y1 = y[i], y2 = y[j];
            int a = x1 - x2;
			int b = y1 - y2;
            int c = x1 * y2 - x2 * y1;
			change(a, b, c);
			mp[{{a,b}, c}]++;
		}
	}
	ll ans = nc3(n);

	for(auto x : mp) {
		ll xx = rec[x.vv];
		ans -= nc3(xx);
	}
	cout<<ans<<'\n';


	return 0;
}

/*
5
0 0
1 0
2 0
3 0

*/