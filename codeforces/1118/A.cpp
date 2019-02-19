#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll a , b , n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    while(q--){
        cin>>n>>a>>b;
        ll c = a*2;
        c = min(c , b);
        ll sum = (n/2LL) *c;
        sum += (n&1)*a;
        cout<<sum<<'\n';
    }
    return 0;
}