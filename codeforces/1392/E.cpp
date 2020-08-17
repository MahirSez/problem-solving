#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;
ll ara[50][50];

int main()  {
    int n;
    cin>>n;
    // memset(ara , -1 , sizeof ara);

    for(int i = 1 ; i <  n ; i += 2) {
        for(int j = 0 ; j < n ; j++ ) {
            ara[i][j] = 1LL<<(i + j - 1);
        }
    }

    for(int i =0 ; i < n ; i++ ) {
        for(int j =0 ; j < n ; j++ ) {
            cout<<ara[i][j]<<" ";
        }
        cout<<endl;
    }

    int q;
    cin>>q;
    while(q--) {
        ll val;
        cin>>val;

        int x = 0 , y = 0;

        cout<<"1 1"<<endl;

        for(int i =0 ; i < 2*n - 2 ; i ++) {

            if(x == n-1) y++;
            else if(y == n-1 ) x++;
            else if( val & (1LL << i)  ) {
                if(ara[x][y+1] == 1LL<<i ) y++;
                else x++;
            }
            else {
                if(ara[x][y+1] == 0) y++;
                else x++;
            }
            cout<<x+1<<" "<<y+1<<endl;
        }
    }
    return 0;

}