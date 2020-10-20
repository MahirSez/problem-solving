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

    int n ;
    cin>>n;
    ll man = 0 , eu = 0 , ch = -INF;
    while(n--) {
        ll tmp;
        cin>>tmp;
        man += abs(tmp);
        eu += tmp*tmp;
        ch = max(ch , abs(tmp) );
    }
    double eeu = sqrt(1.0*eu);
    cout<<man<<'\n';
    cout<<setprecision(12)<<fixed<<eeu<<'\n';
    cout<<ch<<'\n';
    return 0;
    
}