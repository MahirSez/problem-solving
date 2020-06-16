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
        string s = "";
        s += str[0];
        
        for(int i =1 ; i < n-2 ; i++ ) {
            
            s += str[i];
            if(str[i] == str[i+1]) i++;
        }
        s += str[n-1];
        cout<<s<<'\n';
    }
    return 0;
    
}