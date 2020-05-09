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
    int t;
    cin>>t;
    while(t--) {
        
        int n0 , n1 , n2;
        cin>>n0>>n1>>n2;
        if(n1 ==0 ) {
                
            assert(n0 == 0 || n2 == 0);
            
            if(n0) for(int i =0 ; i <= n0 ; i++ ) cout<<0;
            if(n2) for(int i =0 ; i <= n2 ; i++ ) cout<<1;
            
        }
        else {
                
            string str = "";
        
            for(int i =0 ; i <= n1 ; i++ ) str += char( (i%2) + '0');
            
            for(int i =0 ; i <=n0; i++ ) cout<<0;
            for(int i =0 ; i <=n2; i++ ) cout<<1;
            for(int i = 2 ; i < str.size() ; i++ ) cout<<str[i];
            
        }
        cout<<'\n';
    }
    return 0;
}