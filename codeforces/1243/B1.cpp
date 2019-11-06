#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e5 + 6;
int vis[MAX];

string s1  , s2;    
int n;


bool ok() {
    
//    memset(vis, 0 , sizeof vis);
    
    vector<int>vec;
    for(int i =0 ; i < n ; i++ ) {
        
        if(s1[i] != s2[i]) vec.push_back(i);
    }
    if(vec.size() > 2) return 0;
    if(vec.size() == 0 ) return 1;
    
    
    if(vec.size() ==1 ) {
        
        return 0;
    }
    
    swap(s1[vec[0]] , s2[vec[1]]);
//    swap(s1[vec[1]] , s2[vec[0]]);
    return (s1 == s2);
}

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        cin>>n>>s1>>s2;
        if(ok()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}