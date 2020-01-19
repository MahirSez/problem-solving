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
int ara[3][MAX];

set<pii>s;

void Insert(int r1 , int c1 , int r2 , int c2) {
    
    if(r1 == 1) swap(c1 , c2);
    
    s.insert({c1 , c2});
}

void Erase(int r1 , int c1 , int r2 , int c2) {
    
    if(r1 == 1) swap(c1 , c2);
    
    s.erase({c1 , c2});
}


int main()
{
    fastRead;
    int n , q;
    cin>>n>>q;
    
    
    while(q--) {
        
        int r , c;
        cin>>r>>c;
        r--;
        if(ara[r][c] == 0 ) {
            
            ara[r][c] = 1;
            
            if(ara[r^1][c-1])  Insert(r , c , r^1 , c-1);
            if(ara[r^1][c])  Insert(r , c , r^1 , c);
            if(ara[r^1][c+1])  Insert(r , c , r^1 , c+1);
        }
        else {
            
            ara[r][c] =  0;
            
            if(ara[r^1][c-1])  Erase(r , c , r^1 , c-1);
            if(ara[r^1][c])  Erase(r , c , r^1 , c);
            if(ara[r^1][c+1])  Erase(r , c , r^1 , c+1);
        }
        
        if(s.empty()) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    return 0;
    
}