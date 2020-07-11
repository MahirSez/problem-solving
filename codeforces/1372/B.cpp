#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int N = 1e6 + 6;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int main()
{
    fastio;
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int rt = min((int)sqrt(n) + 10, n-1);
		int lcm = n-1, aa = 1, bb = n-1;

		for(int i = 2 ; i <= rt ; i++ ) {
			if(n%i) continue;
			int a = i;
			int b = n-i;
			ll tmp = 1LL*a*b/__gcd(a,b);
			if(tmp < lcm) {
				aa = a;
				bb = b;
				lcm = tmp;
			}

			a = n/i;
			b = n-a;
			tmp = 1LL*a*b/__gcd(a,b);
			if(tmp < lcm) {
				aa = a;
				bb = b;
				lcm = tmp;
			}

		}
		cout<<aa<<" "<<bb<<'\n';

	}
    return 0;
}