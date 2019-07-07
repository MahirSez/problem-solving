#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  n ;
    string str;
    cin>>n>>str;

    int one = 0 , zero = 0;
    for(auto x : str) {
        if( x == '1') one++;
        else zero++;
    }
    if( zero != one) cout<<1<<endl<<str<<endl;
    else {
        cout<<2<<endl;
        cout<<str[0]<<" ";
        for(int i =1 ; i < n ; i++ ) cout<<str[i];
        cout<<endl;
    }
    return 0;
}
