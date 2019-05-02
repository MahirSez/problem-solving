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
int n , ara[MAX];
map<int,int>mp;

vector<int>edg[MAX];

int main()
{
	fastRead;
	int mx = -2e9;
	cin>>n;

    for(int i =1 ; i <= n ; i++) {
		cin>>ara[i];
		mp[ara[i]]++;
        mx = max(mx , ara[i]);
    }

    int cnt1 = mp[mx] , cnt2 = mp[mx-1];

    for(int i =1  ; i < n ; i++ ) {

		int u , v;
		cin>>u>>v;
		edg[u].push_back(v);
		edg[v].push_back(u);
    }

	int ans = mx + 2;

    for(int i =1 ; i<= n ; i++ ) {

		int tot1 = 0 , tot2 = 0;
        for(auto x : edg[i]) {

            if( ara[x] == mx) tot1++;
            if( ara[x] == mx-1) tot2++;
        }

        if( ara[i] == mx) tot1++;

		if( cnt1 ==1 && ara[i] == mx) {

            if(tot2 == cnt2) ans = mx;
            else ans = min(ans , mx+1);
		}

		else if( cnt1 == tot1) ans = min(ans , mx + 1);
    }

    cout<<ans<<endl;
    return 0;
}
