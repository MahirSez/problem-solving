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
int n;


int failureFunction(string &str) {

    
    int n = str.size();
    vector<int>pre(n);
    
    for(int i =1 ; i < n ; i++ ) {
        
        int j = pre[i-1];
        
        while( j > 0 && str[j] != str[i] ) {
            j = pre[j-1];
        }
        if( str[j] == str[i] ) j++;
        pre[i] = j;
    }
    
    return pre[n-1];
}


int main()
{
    cin>>n;
    
    string ans = "";
    
    cin>>ans;
    
    for(int i =1 ; i < n ; i++ ) {
        
        string tmp ;
        cin>>tmp;
        
        int mn = min(tmp.size() , ans.size());
        
        string str = "";
        for(int j =0 ; j < mn ; j++ ) str += tmp[j];
        str += '#';
        for(int j = ans.size() - mn; j < ans.size() ; j++ ) str += ans[j];
        
        
        int ret = failureFunction(str);
        
        for(int i = ret ; i < tmp.size() ; i++ ) ans += tmp[i];
    }
    
    cout<<ans<<'\n';
    return 0;
}