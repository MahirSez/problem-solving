#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int  n , s1 , s2;
    while(t--) {
        cin>>n>>s1>>s2;
        int both = s1 + s2 - n;
        
        cout<<max(s1  , s2) - both + 1<<'\n';
        
    }
    return 0;
}