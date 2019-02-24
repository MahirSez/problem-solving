#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll  w1 , h1 , w2 , h2 , ans;
    cin>>w1>>h1>>w2>>h2;
    ll w = max(w1 , w2);
    ll h = h1 + h2;
    ans = (w+h)*2 + 4;
    cout<<ans<<endl;
    return 0;
}