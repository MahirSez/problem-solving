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

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int two = 0, one = 0;
        for(int i =0 ;i <n ; i++ ) {
            int tmp;
            cin>>tmp;
            if(tmp == 2) two++;
            else one++;
        }
        two %=2 ;
        if(two && one < 2) {
            cout<<"NO"<<'\n';
            continue;
        }
        one -=2;
        cout<<(one%2 ? "NO": "YES")<<'\n';
    }
    return 0;

}