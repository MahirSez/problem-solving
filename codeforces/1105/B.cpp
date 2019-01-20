#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string str , pat;
int n , k;
vector<int>edg[30];
int main()
{
    fastRead;
    cin>>n>>k>>str;
    str +='*';
    int cnt= 0;
    for(int i =0 ; i < n ; i++ ) {
        cnt++;
        if( str[i] != str[i+1]) {
            edg[str[i]-'a'].push_back(cnt);
            cnt = 0;
        }
    }

    int ans = 0;
    for(int i =0 ; i < 26 ; i++ ) {
        int tot = 0;

        for(int j =0 ; j < edg[i].size() ; j++ ) {

            tot += edg[i][j]/k;
        }
        ans = max(tot , ans);
    }
    cout<<ans<<endl;
    return 0;

}
