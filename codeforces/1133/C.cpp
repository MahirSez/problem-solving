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
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i];
        mp[ara[i]]++;
    }
    int ans =0;
    for(int i =0 ; i < n ; i++ ) {
        int frm = ara[i];
        int tmp = 0;
        for(int  cnt = 0; cnt < 6 ; cnt++ ) {
            tmp += mp[frm++];
        }
        ans = max(tmp , ans);
    }
    cout<<ans<<endl;
    return 0;
}