#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         2e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e5 + 5;

/*
10
1010111110
1011101101
*/

int main()
{
    fastRead;
    int n;
    cin>>n;
    string s1, s2, ss1, ss2;
    cin>>s1>>s2;
    
    if(s1 == s2) {
        cout<<0<<'\n';
        return 0;
    }
    ss1 = s1, ss2 = s2;
    sort(ss1.begin(), ss1.end());
    sort(ss2.begin(), ss2.end());
    if(ss1 != ss2) {
        cout<<-1<<'\n';
        return 0;
    }
    
    set<int>st1, st2;
    for(int i =0 ; i < n ; i++ ) {
        if(s1[i] == s2[i]) continue;
        if(s1[i] =='1') st1.insert(i);
        else st2.insert(i);
    }
    
//    for(auto x : st1) cout<<x<<" ";
//    cout<<'\n';
//    for(auto x : st2) cout<<x<<" ";
//    cout<<'\n';    
    int ans = 0;
    
    for(int i = 0 ; i < n ; i++ ) {
        
        vector<int>id1, id2;
        
        int now  ,nn = -1 ;
        if(*st1.begin() < *st2.begin()) now = 1;
        else now = 0;
        
//        cout<<i<<" "<<now<<'\n';
        
        while(1) {
            
            if(now) {
                auto ret = st1.lower_bound(nn);
                if(ret == st1.end()) break;
                id1.push_back(*ret);
                nn = *ret;
            }
            else {
                
                auto ret = st2.lower_bound(nn);
                if(ret ==st2.end()) break;
                id2.push_back(*ret);
                nn = *ret;
            }
            now ^=1;
        }
        if(id1.size() > id2.size()) id1.pop_back();
        if(id1.size() < id2.size()) id2.pop_back();
        
        for(auto x : id1) {
//            cout<<x<<" "<<'\n';
            st1.erase(x);
        }
        for(auto x : id2) {
//            cout<<x<<'\n';
            st2.erase(x);
        }
        ans++;
        if(st1.empty()) {
            cout<<ans<<'\n';
            return 0;
        }
    }
    
    return 0;
}