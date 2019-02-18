#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll n , m ,k;
ll ara[1000006] , sum , koybar;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(false);
    cin>>n>>m>>k;
    for(int i =0 ; i < n ; i++) cin>>ara[i];
    sort(ara , ara + n);
    reverse(ara , ara +n);
    koybar = (m / (k+1));
    // cout<<koybar<<endl;
    sum = koybar * (ara[0] * k );
    sum += koybar * ara[1];
    // cout<<sum<<endl;
    ll baki = m%(k+1);
    sum += baki * ara[0] ;
    cout<<sum<<endl;
    return 0;
}