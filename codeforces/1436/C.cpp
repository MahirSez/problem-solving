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

ll fact[N];


int main()  {
    fastio;

    int n, x , pos;
    cin>>n>>x>>pos;
    fact[0] = 1;

    vector<int>taken(n+1);
    for(int i =1;  i <=n ; i++ ) {
        fact[i] = (1LL*fact[i-1] * i)%MOD;
    }
    int boro = n - x;
    int soto = x-1;

    int l = 0, r = n;
    ll ans = 1;


    while(l < r) {
        int mid = (l+r)/2;

        taken[mid] = 1;

        // cout<<mid<<'\n';
        if(mid == pos) {
            l = mid + 1;
        }
        else if(mid < pos) {
            ans *= soto;
            ans %= MOD;
            soto--;

            l = mid +1;
        }
        else {
            ans *= boro;
            ans %= MOD;
            boro --;
            r = mid;
        }
    }

    int baki = 0;
    for(int i = 0; i < n ; i++ ) {
        if(taken[i] ==0) baki++;
    }

    // cout<<baki<<'\n';
    

    ans *= fact[baki];
    ans%= MOD;
    cout<<ans<<'\n';
    return 0;


    
}