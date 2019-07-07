#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int ara[MAX];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    sort(ara , ara + n);
    deque<int>dq;


    for(int i = 0 , flg = 0 ; i < n ; i++ , flg^=1) {

        if( flg) dq.push_back(ara[i]);
        if( !flg) dq.push_front(ara[i]);
    }
    int i = 0;
    while(!dq.empty()) {
        ara[i++] = dq.front();
        dq.pop_front();
    }
    for(int i = 0 ; i < n ; i++ ) {

        int pre = (i-1 + n)%n;
        int pst = (i+1)%n;
        if( ara[pre] + ara[pst] <= ara[i] ) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    for(int i =0 ; i < n ; i++ ) {
        cout<<ara[i]<<" ";
    }
    cout<<endl;
    return 0;
}
