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

int main()  {
    fastio;
    int n;
    cin>>n;
    vector<int>vec(n+1);
    for(int i = 0; i < n ; i++ ) cin>>vec[i];
    ll money = 1000;

    for(int i = 1 ; i <=n ; i++ ) {
        if(vec[i] > vec[i-1]) {
            ll stk = money/vec[i-1];
            ll rem = money % vec[i-1];
            money = stk *vec[i] + rem;
        }
    }
    cout<<money<<'\n';
    return 0;
}