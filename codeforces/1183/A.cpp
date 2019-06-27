#include<bits/stdc++.h>
using namespace std;


bool ok(int tmp) {
    int sum = 0;
    while(tmp) {
        sum += tmp%10;
        tmp/=10;
    }
    return (sum%4 ==0 );
}
int main()
{
    int n;
    cin>>n;
    for(int i = n ; ;i++ ) {
        if(ok(i)) {
            cout<<i<<'\n';
            return 0;
        }
    }
    return 0;
}