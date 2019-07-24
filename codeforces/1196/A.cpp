#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000006
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    ll a , b , c;
    cin>>q;
    while( q--) {

        cin>>a>>b>>c;
        cout<<(a+b+c)/2LL<<'\n';
    }
    return 0;
}
