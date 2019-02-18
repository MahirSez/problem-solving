#include<bits/stdc++.h>
using namespace std;
int n , ara[1000006];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(false);
    cin>>n;
    int mx = -1;
    for(int i =0 ; i < n ; i++ )cin>>ara[i] , mx = max(mx , ara[i]);
    int cnt = 0 , mxCnt =0;
    for(int i =0 ; i < n ; i++ ) {
        if( ara[i] ==mx) {
            cnt++;
        }
        else {
            cnt = 0;
        }
        mxCnt = max(mxCnt , cnt);
    }
    cout<<mxCnt<<endl;
    return 0;

}