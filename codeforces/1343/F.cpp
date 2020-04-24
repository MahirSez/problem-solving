#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 300;

set<int>s[MAX] , ss[MAX];

map< set<int> , bool>mp;
int n;

/*
1
6
3 2 5 6
2 4 6
3 1 3 4
2 1 3
4 1 2 4 6
*/

void reset() {
    
    for(int i = 0 ; i < n ; i++ ) ss[i].clear();
    mp.clear();
}

bool check(vector<int>&vec) {

    
    for(int i = 1 ; i < n ; i++ ) {
        
        bool ok = 0;
        set<int>tmp;

        for(int j = i ; j >=0 ; j--) {
            tmp.insert(vec[j]);
            
            
            if(mp[tmp]) ok = 1;
        }
        if(!ok) return 0;
    }
    return 1;
    
}

vector<int>go(int num) {
    
    vector<int>ret;
    
    ret.push_back(num);
    
    while(ret.size() < n ) {
        
        for(int i =0 ; i <n-1 ; i++ )s[i].erase(num);
        
        num = -1;
        
        for(int i =0 ; i < n -1; i++ ) {
            
            if(s[i].size() != 1) continue;
            num = *s[i].begin();
        }
        
        if(num == -1) return vector<int>();
        ret.push_back(num);
    } 
//    for(auto x : ret) cout<<x<<" ";
//    cout<<'\n';
    
    bool ok = check(ret);
    if(ok) return ret;
    return vector<int>();
    
}


int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        cin>>n;
        reset();
        
        for(int i =0 ; i < n-1 ; i++ ) {
            int tmp;
            cin>>tmp;
            while(tmp--) {
                int val;
                cin>>val;
                ss[i].insert(val);
            }
        }
        for(int i =0 ; i < n-1 ;i++ ) mp[ss[i]] = 1;
//        cout<<"\n\n";
//        for(auto x : mp) {
//            for(auto xx : x.first) cout<<xx<<" ";
//            cout<<'\n';
//        }
        
        vector<int>ans;
        
        for(int i = 1 ; i <=n ; i++ ) {
                
            for(int j = 0 ; j < n-1 ; j++ ) s[j] = ss[j];
        
            ans = go(i);
            if(ans.size()) break;
        }
        for(auto x : ans) cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
}
