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

/*
1
4 2
1 2 1 2
*/

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n , k;
        cin>>n>>k;
        vector<int>vec(2*k+5) ,rec(2*k+5) , ara(n);
        for(int i =0  ; i < n ; i++) cin>>ara[i];
        
//        cout<<'\n';
        
        for(int i = 0 , j = n-1 ; i < j; i++ , j--) {
            
            int a = ara[i] , b = ara[j];
            
            if(a > b ) swap(a , b);
            
            int mx = k + b;
            int mn = a + 1;
            
            rec[a+b]++;
            
            vec[mx+1]--;
            vec[mn]++;
            
        }
        int ans = INF;
        int sum = 0;
        
        for(int i = 1 ; i <= 2*k ; i++ ) {
            
            sum += vec[i];
            
            ans = min(ans , n - sum - rec[i]);
            
        }
        cout<<ans<<'\n';
        
    }
    return 0;
    
}