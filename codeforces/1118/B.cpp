#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000006
using namespace std;
ll ara[MAX] , preOdd[MAX] , preEven[MAX] , postOdd[MAX] , postEven[MAX];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i =1 ; i <= n ; i++ ) cin>>ara[i];
    for(int i =1 ; i <=n ; i++ ) {
        if( i &1 ) {
            preOdd[i] = preOdd[i-1] + ara[i];
            preEven[i] = preEven[i-1];
        }
        else {
            preEven[i] = preEven[i-1] + ara[i];
            preOdd[i] = preOdd[i-1];
        }
    }

    for(int i = n ; i >= 1 ; i--) {

        postEven[i] = postEven[i+1];
        postOdd[i] = postOdd[i+1];

        if( i&1 ) postOdd[i] += ara[i];
        else postEven[i] += ara[i];
    }

    int ans = 0;
    for(int i =1 ; i <= n ; i++ ) {

        ll sum1 = preOdd[i-1] + postEven[i+1];
        ll sum2 = preEven[i-1] + postOdd[i+1];
        if( sum1 == sum2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}