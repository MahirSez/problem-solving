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

int main() {
    int n , m , k;
    cin>>n>>m>>k;

    string one = "Timur" , two = "Marsel";
    if(n%2 ==0) {
        cout<<two<<'\n';
        return 0;
    }

    int div = 0;
    for(ll i = 2 ; i*i <= m ; i++) {
        if(m % i) continue;
        int div1 = i;
        int div2 = m/i;
        if(div1 >=k || div2 >= k) div = 1;
    }

    if(k ==1 && m > 1) div = 1;

    if( div) cout<<one<<'\n';
    else cout<<two<<'\n';
    return 0;


}