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
        int n = str.size();
        
        vector<string> vec;
        
        for(int i = 0 ,j = n-1; i < n  ; i++ ,j-- ) {
            
            if(str[i] == '0') continue;
            
            string s = "";
            s += str[i];
            for(int k =0 ; k < j ; k++ ) s += '0';
            vec.push_back(s);
            
        }
        cout<<vec.size()<<'\n';
        for(auto x : vec) cout<<x<<" ";
        cout<<'\n';
    }
    
    return 0;
    
}