#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
vector< vector<int> > v;
int ara[MAX] , dist[MAX];
int n , m;
int solve(vector<int>&vec, int col) {
    
    for(int i = col  , j = 1; j <= n ; i += m , j++ ) {
        
        ara[i] = j;
        dist[j-1] = 0;
    }
    
    
    int cst = n;
    
    
    for(int i = 0 ; i < vec.size() ; i++ ) {
        
        int now = i+1;
        
        int val = vec[i];
        
        if(ara[val] == 0 ) continue;
        
        int dd = now - ara[val];
        if(dd < 0 ) dd += n;
        
        dist[dd]++;
        
    }
    
    for(int i =0 ; i < n ; i++ ) {
        
        int tmp = i + n - dist[i];
        cst = min(cst , tmp);
    }
    
    
    
    for(int i = col  , j = 1; j <= n ; i += m , j++ ) {
        
        ara[i] = 0;
        
    }    
    return cst;
    
}


int main()
{
    fastRead;
    
    cin>>n>>m;
    for(int i =0 ; i < n ; i++ ) {
        vector<int> tmp;
        for(int j =0 ; j < m ; j++ ) {
            int in;
            cin>>in;
            tmp.push_back(in);
        }
        v.push_back(tmp);
    }
    int ans = 0;
    for(int j =0 ; j < m ; j++ ) {
        vector<int>tmp;
        for(int i = 0 ; i < n ; i++ ) tmp.push_back(v[i][j]);
        ans += solve(tmp , j+1);
    }
    cout<<ans<<'\n';
    return 0;
    
}