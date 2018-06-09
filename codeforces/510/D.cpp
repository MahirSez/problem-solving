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
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n, len[MAX],cst[MAX] ,tgt;
map<int,map<int,int> >dp;
map<int,map<int,bool> >vis;

int solve(int id , int gcd) {
    if( id == n)  {
        if( gcd == 1) return 0;
        return INF;
    }
    if(vis[id][gcd]) return dp[id][gcd];
    vis[id][gcd] = true;
    int tmp = INF;
    tmp = min( tmp, solve(id+1 , __gcd(gcd ,len[id]) )+ cst[id] );
    tmp = min( tmp , solve( id+1 , gcd) );
    return dp[id][gcd] = tmp;
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ;i++) cin>>len[i];
    for(int i =0 ; i < n ;i++) cin>>cst[i];
    int ans = solve(0,0);
    if( ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
