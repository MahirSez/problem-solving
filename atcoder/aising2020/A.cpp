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
    int l ,r, d;
    cin>>l>>r>>d;
    int cnt = 0;
    for(int i = l; i <=r ; i ++) {
        if(i%d ==0)cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}