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
        
        int n;
        cin>>n;
        if((n/2)%2 ) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        
        ll sum1 = 0;
        for(int i =2 , j =0  ; j <n/2 ; i+=2 , j++) {
            cout<<i<<" ";
            sum1 += i;
        }
        
        for(int i =1 , j =0  ; j <n/2-1 ; i+=2 , j++) {
            cout<<i<<" ";
            sum1 -= i;
        }
        cout<<sum1<<'\n';
    }
    return 0;
    
}