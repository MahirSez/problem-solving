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
int mark[N];
vector<int>prm;

void seive() {

    
    for(ll i = 2; i*i < N ; i++ ) {
        if(mark[i]) continue;
        for(ll j = i*i ; j < N ; j+= i) {
            mark[j] = 1;
        }
    }

    for(int i =2 ; i < N ; i++ ) {
        if(mark[i] == 0) prm.push_back(i);
    }

    // cout<<prm.size()<<'\n';
    // exit(0);
}


int main()  {
    fastio;

    seive();
    int t;
    cin>>t;

    while(t--) {
        int d;
        cin>>d;

        int id = lower_bound(prm.begin() , prm.end() , d+1) - prm.begin();

        int val1 = prm[id];

        id = lower_bound(prm.begin() ,prm.end(), val1 + d) - prm.begin();
        assert(id < prm.size());

        int val2 = prm[id];

        ll ans = 1LL*val1 * val2;
        cout<<ans<<'\n';
    }
    return 0;
}