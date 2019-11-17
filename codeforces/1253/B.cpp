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

int main()
{
    fastRead;
    int n;
    cin>>n;
    
    map<int,int>mp1 , mp2;
    bool ok = 1;
    vector<int>ans;
    int cnt = 0;
    
    for(int i =0 ; i < n && ok; i++ ) {
        
        int tmp;
        cin>>tmp;
        
        
        if(tmp > 0 && mp1.count(tmp)) ok = 0;
        
        if(tmp > 0 && mp2.count(tmp) ) ok = 0;
        if(tmp < 0 && mp2.count(-tmp) == 0 ) ok = 0;
        
        
        mp1[abs(tmp)] = 1;
        
        if(tmp > 0 ) mp2[tmp]++;
        else {
            if(mp2[ -tmp] !=1) ok = 0;
            mp2.erase(-tmp);
        }
        
        
        
        cnt++;
        
        if(mp2.size() == 0 ) {
            
            mp1.clear();
            mp2.clear();
            ans.push_back(cnt);
            cnt = 0;
        }
    }
    
    if(mp2.size() || mp1.size() ) ok = 0;
    
    
    if(!ok) cout<<-1<<'\n';
    else {
        cout<<ans.size()<<'\n';
        for(auto x : ans) cout<<x<<" ";
        cout<<
        '\n';
    }
    
    return 0;
}