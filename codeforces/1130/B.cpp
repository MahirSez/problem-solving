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
int n ;
vector<int>ara[MAX];
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < 2*n ; i++  ) {
        int tmp;
        cin>>tmp;
        ara[tmp].push_back(i);
    }

    int nowX = 0 , nowY = 0;

    ll ans = 0;

    for(int i =1 ; i<=n ; i++ ) {

        int id1 = ara[i][0];
        int id2 = ara[i][1];
        int tmp1 = abs(nowX - id1) + abs(nowY - id2);
        int tmp2 = abs(nowX - id2) + abs(nowY - id1);
        ans += min(tmp1 , tmp2);
        nowX = id1 ;
        nowY = id2;
    }
    cout<<ans<<endl;
    return 0;
}