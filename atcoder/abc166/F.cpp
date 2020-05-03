#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int ara[3];
string str[MAX];
int main()
{
    fastRead;
    
    int n ;
    cin>>n;
    cin>>ara[0]>>ara[1]>>ara[2];
    
    bool ok = 1;
    
    vector<char>vec;
    
    for(int i =0 ; i < n ; i++ ) cin>>str[i];
    
    for(int i =0 ;  i < n ; i++) {
        
        string s = str[i];
        
        if( ara[ s[0]-'A'] > ara[s[1]-'A']) {
            ara[ s[0]-'A']--;
            ara[ s[1]-'A']++;
            vec.push_back(s[1]);
        }
        else if( ara[ s[0]-'A'] < ara[s[1]-'A'] ) {
            ara[ s[0]-'A']++;
            ara[ s[1]-'A']--;            
            vec.push_back(s[0]);
        }
        else {
                
            if( i < n -1 && (str[i+1][0] == s[0] || str[i+1][1] == s[0] ) ) {
                ara[ s[0]-'A']++;
                ara[ s[1]-'A']--;            
                vec.push_back(s[0]);
            }
            else {
                ara[ s[0]-'A']--;
                ara[ s[1]-'A']++;
                vec.push_back(s[1]);                
            }
        }
        
        if(ara[0] < 0 || ara[1] < 0 || ara[2] < 0 ) ok = 0;
    }
    if(!ok) cout<<"No\n";
    else {
        cout<<"Yes\n";
        for(auto x : vec) cout<<x<<'\n';
    }
    return 0;
}