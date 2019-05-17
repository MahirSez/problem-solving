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
int ara[30];
int main()
{
	fastRead;
	int n;
	cin>>n;
	for(int i =0 ; i < n ; i++ ) {
		string str;
		cin>>str;
		ara[str[0]-'a']++;
	}

    int ans = 0;
    for(int i = 0 ; i < 27 ; i++ ) {

        int cnt = ara[i];

        int cnt1 = cnt/2;
        int cnt2 = cnt/2 + (cnt&1);

        ans += (cnt1)*(cnt1-1)/2;
        ans += (cnt2)*(cnt2-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}
