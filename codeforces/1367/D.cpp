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
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        int n;
        cin>>n;
        vector<int>vec(n) , mark(n);
        vector<char>ans(n);
        for(int i =0 ; i < n ; i++ ) cin>>vec[i];
        map<char, int>mp;
        for(auto x: str) mp[x]++;
        
        for(char ch = 'z' ; ch >='a' ; ch--) {
            
            vector<int>tmp;
        
            for(int i =0 ; i < n ; i++ ) {
                if(mark[i]) continue;
                
                int cst = 0;
                for(int j =0 ; j < n ; j++ ) {
                    
                    if(mark[j]) cst += abs(i-j);
                }
                if(cst == vec[i]) tmp.push_back(i);
            }
            if(mp[ch] >= tmp.size()) {
                
                for(auto x : tmp) {
                    ans[x] = ch;
                    mark[x] = 1;
                }
            }
        }
        
        for(int i =0 ; i < n ; i ++) {
            cout<<ans[i];
        }
        cout<<'\n';
    }
    return 0;
}