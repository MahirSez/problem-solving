#include<bits/stdc++.h>
using namespace std;
int ara[300] ,  k , n;
int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    
    cin>>t;
    while( t-- ) {
        cin>>n>>k;
        for(int i =0 ; i < n ; i++ ) cin>>ara[i];
        sort(ara , ara + n );
        
        if( ara[0] + k < ara[n-1] - k) cout<<-1<<'\n';
        else cout<<ara[0] + k<<'\n';
    }
    return 0;
}