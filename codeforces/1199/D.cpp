#include<bits/stdc++.h>
#define ll long long int
using namespace std;

const int MAX =2e5 + 5;

int ara[MAX] , mark[MAX];

int  n , q , id , pay[MAX];



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    for(int  i=1 ; i <= n ; i++ ) cin>>ara[i];
    cin>>q;
    
    while( q-- ) {
        
        
        int typ;
        cin>>typ;
        if( typ == 2) {
            
            int val;
            cin>>val;
            
            pay[++id] = val;
        }
        else {
            
            int no , val;
            cin>>no>>val;
            ara[no] = val;
            
            mark[no] = id;
        }
    }
    
    
    for(int i = id -1; i>= 0 ; i-- ) {
        
        pay[i] = max(pay[i] , pay[i+1]);
    }
    
    for(int i =1 ; i <=n ; i++ ) {
        
        int payno = mark[i];
        int now = ara[i];
        
        int getMax = pay[payno+1];
        
        cout<<max(now , getMax)<<" ";
    }
    cout<<'\n';
    return 0;
    
}
