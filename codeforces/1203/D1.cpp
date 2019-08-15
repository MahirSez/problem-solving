#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

string s1 , s2;
int a1[MAX] , a2[MAX];
int n , m;
int main()
{
    fastRead;
    cin>>s1>>s2;
    
    n = s1.size();
    m = s2.size();
    
    int id = 0;
    for(int  i =0 ; i < m ; i++ ) {
        
        
        while(s2[i] != s1[id]) id++;
        
        a1[i] = id++;
    }
    
    id = n-1;
    for(int i = m-1 ;i>=0 ; i-- ) {
        
        while( s2[i] != s1[id] ) id--;
        
        a2[i] = id--;
    }
    

    int ans = max(a2[0] , n - a1[m-1] - 1);
    for(int i = 0 ; i < m -1 ; i++ ) {
        ans = max(ans , a2[i+1] - a1[i] - 1);
    }
    
    
    cout<<ans<<'\n';
    return 0;
    
}