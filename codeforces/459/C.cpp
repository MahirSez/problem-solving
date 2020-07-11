#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;


const int INF = 1e9;
const ll MOD = 1e9 + 7;
const int N = 1e3 + 3;


int ara[N][N];

int main() {
	fastio;
	int n, k , d;
	cin>>n>>k>>d;

	for(int j = 2 ; j <= n ; j++ ) {

		ara[d][j] ++;
		
		for(int i = d ; i >=1 ; i--) {
			
			ara[i][j] += ara[i][j-1];

			if(ara[i][j] >= k) {
				ara[i-1][j] += ara[i][j] / k;
				ara[i][j] %= k;
			}
		}

		if(ara[0][j]) {
			cout<<-1<<'\n';
			return 0;
		}
	}
	for(int i =1 ; i <=d ; i++ ) {
		for(int j = 1 ; j<=n ; j++  ) {
			cout<<ara[i][j]+1<<" ";
		}
		cout<<'\n';
	}
	
	return 0;
}