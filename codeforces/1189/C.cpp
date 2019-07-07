#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int ara[MAX] ,sum[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1; i <= n ; i++ ) cin>>ara[i];
    for(int i =1 ; i <=n ; i++) sum[i] = sum[i-1] + ara[i];
    int q;
    cin>>q;
    while( q-- ) {
        int l , r;
        cin>>l>>r;
        int tot = sum[r]- sum[l-1];
        cout<<tot/10<<'\n';
    }
    return 0;
}
