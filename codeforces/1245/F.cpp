#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define plp         pair<ll , pii>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e4 + 4;
vector<int>L , R;


ll dp[40][2][2][2][2];

ll solve(int id , int isSmall1 , int isBig1 , int isSmall2 , int isBig2) {

    if(id == L.size()) return 1LL;
    
    ll &ret = dp[id][isSmall1][isSmall2][isBig1][isBig2];
    if(ret != -1 ) return ret;
    
    ret = 0;
    
    for(int i =0 ; i <=1 ; i++ ) {
        
        if(isSmall1 == 0 && i > R[id] ) continue;
        if(isBig1 == 0 && i< L[id]) continue;
        
        for(int j =0 ; j <=1 ; j++ ) {
                
            if(i ==1 && j ==1 ) continue;
            
            if(isSmall2 == 0 && j > R[id]) continue;
            if(isBig2 == 0 && j < L[id]) continue;
            
            ret += solve(id+1 , (isSmall1 |(i < R[id])) , (isBig1 | (i> L[id]) )  , (isSmall2 | (j < R[id])) , (isBig2 | (j >L[id])) );
        }
    }
    return ret;
    
}

int main()
{
    fastRead;
    int t;
    cin>>t;
    
    while(t--) {
        
        int a , b;
        cin>>a>>b;
        L.clear();
        R.clear();
        for(int i =0 ; i <31 ; i++ ) {
            
            L.push_back(a%2);
            R.push_back(b%2);
            a/=2;
            b/=2;
        }
        
        reverse(L.begin() , L.end());
        reverse(R.begin() , R.end());
        
//        for(auto x : L) cout<<x<<" ";
//        cout<<'\n';
//        for(auto x : R) cout<<x<<" ";
//        cout<<'\n';        
        memset(dp ,-1 , sizeof dp);
        
        cout<<solve(0 , 0  ,0 , 0 , 0)<<'\n';
    }
    return 0;
}