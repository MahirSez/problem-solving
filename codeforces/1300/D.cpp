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

ll x[MAX] , y[MAX];
int main()
{
    fastRead;
    
    int n;
    cin>>n;
    
    for(int i =0 ; i < n ; i++ ) cin>>x[i]>>y[i];
    x[n] = x[0];
    y[n] = y[0];
    
    if(n&1) {
        cout<<"NO\n";
        return 0;
    }
    
    bool ok = 1;
    for(int i = 0 , j = n/2; j < n ; j++ , i++)  {
        
        ll up1 = y[i] - y[i+1];
        ll down1 = x[i] - x[i+1];
        ll gcd1 = abs(__gcd(up1 , down1));
        up1/= gcd1 , down1 /= gcd1;
        
        ll up2 = y[j] - y[j+1];
        ll down2 = x[j] - x[j+1];
        ll gcd2 = abs(__gcd(up2 , down2));
        up2/= gcd2 , down2 /= gcd2;        
        
        ll dst1 = ( y[i] - y[i+1])*( y[i] - y[i+1]) + ( x[i] - x[i+1])*( x[i] - x[i+1]);
        ll dst2 = ( y[j] - y[j+1])*( y[j] - y[j+1]) + ( x[j] - x[j+1])*( x[j] - x[j+1]);
        
        if(abs(up1) != abs(up2) || abs(down1) != abs(down2) || 1LL*up1*down2 != 1LL*up2*down1 || dst1 != dst2 )  ok = 0;
        
    }
    
    if(ok ) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}   