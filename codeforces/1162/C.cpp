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
int ara[MAX] , cnt[MAX];

map<pii,int>mp;
int main()
{
	fastRead;
	int n 	, k;
	cin>>n>>k;
	for(int i =0 ; i < k ; i++ ) {
		cin>>ara[i];
		cnt[ara[i]]++;
		mp[{ara[i] , ara[i]}] = 1;
	}
	int ans = 3*n-2;
	int tot = 0;



	for(int i = 0 ; i < k ;i++ ) {
        int val = ara[i];
        if(val-1 >= 1 && cnt[val-1]>0) mp[{val , val-1}] = 1;
        if(val+1 <= n && cnt[val+1]>0) mp[{val , val+1}] = 1;


        cnt[val]--;
	}

	cout<<ans- mp.size()<<endl;
	return 0;
}
