#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , ans;
ll ara[MAX];
map<ll, int>mp;

void dfs(int x ,int y , int len) {
    ans = max( len , ans);
    if( mp[x+y] ) {
        mp[x+y]--;
        dfs(y , x+y , len+1);
        mp[x+y]++;
    }
}

int main()
{
    fastRead;
    cin>>n;
    for(int i = 0 ; i < n ; i ++) {
        cin>>ara[i];
        mp[ara[i]]++;
    }
    ans = mp[0];
    for(int i =0 ; i < n ; i++ ) {
        for(int j =0 ; j < n ; j++) {
            if( i ==j ) continue;
            if(ara[i] ==0 && ara[j] ==0 ) continue;
            mp[ara[i]]--;
            mp[ara[j]]--;
            dfs(ara[i] , ara[j] , 2);
            mp[ara[i]]++;
            mp[ara[j]]++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
