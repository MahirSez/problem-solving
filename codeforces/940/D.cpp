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
int main()
{
    fastRead;
    int n;
    cin>>n;
    vector<int>vec(n);
    string str;
    for(int i =0 ; i < n ; i++ ) cin>>vec[i];
    cin>>str;
    
    int l = -INF , r = INF;
    
    for(int i =1 ; i <n ; i++ ) {
        
        if(str[i] == str[i-1]) continue;
        
        if(str[i] == '0') {
            
            int tmp = INF;
            
            for(int j = i  , cnt = 0 ;  cnt < 5 ; cnt++ , j--) tmp = min(tmp , vec[j]);
            r = min(r , tmp - 1);
        }
        
        else {
            
            int tmp = -INF;
            for(int j = i  , cnt = 0 ;  cnt < 5 ; cnt++ , j--) tmp = max(tmp , vec[j]) ;
            
            l = max(l , tmp+1);
        }
        
    }
    
    cout<<l<<" "<<r<<'\n';
    return 0;
    
}