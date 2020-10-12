#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;
int n;
int val[10];

int Try(int x , int y) {
    for(int i = 0 ; i <= n ; i++  ) {
        if(x*i > n) break;

        if((n-x*i) % y == 0 )  {
            val[x] = i;
            val[y] = (n-x*i)/y;

            cout<<val[3]<<" "<<val[5]<<" "<<val[7]<<'\n';
            return 1;
        }
    }
    return 0;
}
int main() {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        memset(val, 0 , sizeof val);

        cin>>n;
        int ok = 0;
        ok = Try(3 , 5);
        if(ok) continue;
        ok = Try(5 , 7);
        if(ok) continue;
        ok = Try(3 , 7);
        if(ok) continue;
        cout<<-1<<'\n';
    }
    return 0;

}