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

int n , m;

string str[200];

map<string,int>mp;

string ans;

bool isPal(string &s) {
    
    for(int i = 0 , j = m-1 ;  i<=j ; i++ , j-- ) {
        
        if(s[i] != s[j])return 0;
    }
    return 1;
}


int main()
{
    fastRead;
    cin>>n>>m;
    
    for(int i = 0 ; i < n ; i++ ) cin>>str[i] , mp[str[i]] = 1;
    
    for(int i =0 ; i < n ; i++ ) {
        
        if(mp[str[i]] != 1 ) continue;
        
        
        string s1 = str[i];
        string s2 = s1;
        reverse(s2.begin() , s2.end());
        
        mp[s1] = 0;
        
        if(mp[s2]) {
            
            ans += s1;
            mp[s2] = -1;
            mp[s1] = -1;
        }
    }
    
    string ss = "";
    
    
    for(int i =0 ; i < n ; i++ ) {
        
        if(mp[str[i]] == -1 ) continue;
        
        if(isPal(str[i])) {
            
            ss = str[i];
            break;
        }
    }
    
    string ans2 = ans;
    
    reverse(ans2.begin() , ans2.end());
    
    string f = ans + ss + ans2;
    
    cout<<f.size()<<'\n';
    cout<<f<<'\n';
    return 0;
    
    
    
    
}