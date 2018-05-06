#include <bits/stdc++.h>
#define ll          long long int
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
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
int n , dp[MAX] , prm[MAX] , str[MAX];
vector<int>edg[MAX];

void sieve() {

    for(int i = 2 ; i < MAX; i++) {
        if( prm[i] == 0) {
            for(int j = i*2 ; j < MAX ; j+=i ) {
                prm[j] = 1;
                edg[j].push_back(i);
            }
        }
    }
}

int main()
{
    fastRead;
    sieve();
    int kop = 1;
    cin>>n;
    for(int i =0; i < n ; i++) {
        int tmp;
        cin>>tmp;
        int ans= 0;
        for(int j = 0 ; j < edg[tmp].size(); j++ ) {
            int node =edg[tmp][j];
//            cout<<node<<" "<<str[node]<<endl;
            ans = max(ans , str[node]);
        }
//        cout<<tmp<<" "<<ans+1<<endl;
        dp[tmp] = ans + 1;
        kop = max( kop , dp[tmp]);
        str[tmp] = dp[tmp];
        for(int j =0 ; j  <edg[tmp].size() ; j++ ) {
            int node = edg[tmp][j];
            str[node] = dp[tmp];
        }
    }
    cout<<kop<<endl;
    return 0;
}
