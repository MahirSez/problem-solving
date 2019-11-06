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

int inversionparity(string &s) {
    
    
    int n = s.size();
    vector<int>vec[30];
    
    int par = 0;
    
    for(int i = n-1 ; i >=0 ; i--) {
        
        int id = s[i] - 'a';
        
        for(int j = id+1 ; j < 26 ; j++ ) par = (par + vec[j].size())%2;
        
        vec[id].push_back(1);
    }
    
    return par;
    
}

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n ; 
        cin>>n;
        string s1 , s2;
        cin>>s1>>s2;
        
        map<char, int>mp1 , mp2;
        
        bool ok = false;
        
        for(auto x : s1) {
            mp1[x]++;
            if( mp1[x]> 1 )  ok = true;
        }
        for(auto x : s2) {
            mp2[x]++;
        }
        
        if(mp1 != mp2) {
            cout<<"NO\n";
            continue;
        }
        
        if(ok) {
            cout<<"YES\n";
            continue;
        }
        
        
        int p1 = inversionparity(s1);
        int p2 = inversionparity(s2);
        
        if(p1 == p2) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}