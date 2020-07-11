#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;


const int INF = 1e9;
const ll MOD = 1e9 + 7;
const int N = 1e3 + 3;

int main() {
    int n;
    cin>>n;
    int ans = 0;

    for(int i =1 ; i <=n ; i++) {
        int tmp;
        cin>>tmp;
        if(i%2 && tmp%2) ans++;
    }
    cout<<ans<<'\n';
    return 0;
}