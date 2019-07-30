#include<bits/stdc++.h>
using namespace std;

const int MAX =1e5 + 5;

int n , x , y;
int ara[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x>>y;
    for(int i =1  ; i <=n ; i++ ) cin>>ara[i];
    
    
    for(int i =1 ; i<= n ; i++ ) {
        
        
        int frm = max(1 , i-x);
        int to = min( n, i + y);
        
        bool ok = true;
        for(int j = frm ; j < i ; j++ ) {
            if(ara[i] > ara[j]) ok = false;
        }
        for(int j = i+1 ; j <=to ; j++ ) {
            if(ara[i] > ara[j] ) ok = false;
        }
        if( ok) {
            cout<<i<<'\n';
            return 0;
        }
    }
}
