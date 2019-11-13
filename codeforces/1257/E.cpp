#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 2e5 + 5;
int col[MAX] , dp[MAX][5] , n;

int solve(int id , int c) {

    if(c > 3) return INF;
    if(id == n+1 ) return 0;
    
    int &ret = dp[id][c];
    if( ret != -1) return ret;
    
    ret = INF;
    ret = min(solve(id , c+1) , (solve(id+1 , c) + (col[id] != c)) );
    
    return ret;
}


int main()
{
    fastRead;
    int nn , m , k;
    cin>>nn>>m>>k;
    n = nn + m + k;

    while(nn--) {
        int tmp;
        cin>>tmp;
        col[tmp] = 1;
    }
    while(m--) {
        int tmp;
        cin>>tmp;
        col[tmp] = 2;
    }
    while(k--) {
        int tmp;
        cin>>tmp;
        col[tmp] = 3;
    }     
    memset(dp , -1 , sizeof dp);
    
    cout<<solve(1 , 1)<<'\n';
    return 0;
}