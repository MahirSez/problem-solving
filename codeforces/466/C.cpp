#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000006
using namespace std;
map<ll , int>mp;
ll ara[MAX] , sum[MAX];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
    ll tot =0;
	for(int i = 1; i <= n ; i++ ) {

        cin>>ara[i];
        tot += ara[i];
        sum[i] = tot;
        mp[tot]++;
	}

	if( tot%3 ) {
		cout<<0<<endl;
		return 0;
	}

	if( tot==0 ) {

        ll tmp = mp[0];
        cout<<(tmp-1)*(tmp-2)/2<<endl;
        return 0;
	}
	ll tgt = tot/3;
	ll cnt = 0;
	tot = 0;
    for(int i = n ; i>= 1 ; i--) {

        mp[sum[i]]--;

		tot += ara[i];
		if( tot != tgt) continue;
        cnt += mp[tgt];
    }
	cout<<cnt<<endl;
	return 0;
}
