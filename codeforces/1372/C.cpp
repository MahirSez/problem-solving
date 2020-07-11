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
		vector<int>vec(n+1);
		for(int i =1; i <=n ; i++ ) cin>>vec[i];
		int ans = 0;

		for(int i =1 ; i <=n ; i++ ) {
			if(vec[i] != i) {
				ans++;
				break;
			}
		}
		if(ans == 0) {
			cout<<0<<'\n';
			continue;
		}

		int frm = 1, to = n;
		for(int i =1; i <=n ; i++) {
			if(vec[i] != i) {
				frm = i;
				break;
			}
		}
		for(int i = n ; i >=1 ; i--) {
			if(vec[i] != i) {
				to = i;
				break;
			}
		}

		for(int i = frm; i <=to ; i++ ) {
			if(vec[i] == i) {
				ans++;
				break;
			}
		}
		cout<<ans<<'\n';
	}
    return 0;
}