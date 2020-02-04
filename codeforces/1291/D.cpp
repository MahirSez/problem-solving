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

const int MAX = 2e5 + 6;
string str;
int ara[30][MAX];

int main()
{
    fastRead;
    cin>>str;
    
    
    int n = str.size();
    
    
    for(int i =1 ; i <=n ; i++ ) {
        
        int id = (str[i-1] - 'a'+1);
        ara[id][i] = 1;
        
        for(int j =1 ; j <= 26 ; j++ ) ara[j][i] += ara[j][i-1];
    }

    
    int q;
    cin>>q;
    while(q--) {
        
        int l , r;  
        cin>>l>>r;
    
        if(l == r) {
            cout<<"Yes\n";
            continue;
        }
        
        int diff = 0;
        for(int i = 1 ; i<=26 ; i++ ) {
            
            if(ara[i][r] - ara[i][l-1] ) diff++;
        }
        
        if(str[r-1] == str[l-1] && diff <= 2 ) cout<<"No\n";
        else cout<<"Yes\n";
    }
    return 0;
    
    
}