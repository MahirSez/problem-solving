#include <bits/stdc++.h>
#include <ios>
#include <iostream>
using namespace std;
using ll =long long;


void solve() {
	ll c[3];
	ll a[5];
	for(int i=0;i<3;i++) cin >> c[i];
	for(int i=0;i<5;i++) cin >> a[i];

	for(int i=0;i<3;i++) {
		c[i]-=a[i];
		if(c[i]<0) {
			cout << "NO\n";
			return;
		}
	}

	a[3]-=min(c[0],a[3]);
	c[2]-=a[3];
	a[4]-=min(c[1],a[4]);
	c[2]-=a[4];

	if(c[2]>=0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}


}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;

}