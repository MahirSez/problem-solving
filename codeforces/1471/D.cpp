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
vector<int>prm;
int mark[N], rec[N];

vector<int>factor[N];

void seive() {

    for(ll i = 2 ;i < N ; i++) {
        if(mark[i]) continue;

        for(ll j = i*i ; j < N ; j+=i) {
            mark[j] = 1;
        }
    }

    for(int i =2 ; i < N ; i++ ) {
        if(mark[i] == 0) prm.push_back(i);
    }


    for(auto x : prm) {

        ll tmp = x;

        while(tmp < N ) {
            factor[tmp].push_back(x);
            tmp += x;
        }
    }

    for(int i =1; i < N ; i++ ) {

        rec[i] = 1;

        
        for(auto x : factor[i]) {

            int cnt = 0;
            int tmp = i;
            while(tmp % x == 0 ) {
                tmp /= x;
                cnt++;
            }

            if(cnt %2 )rec[i] *= x;
        }
    }



    // for(int i= 0 ;i < 10 ; i++ ) cout<<prm[i]<<" ";
    // cout<<'\n';
}

void solve() {


    int n;
    cin>>n;

    map<int,int>mp;

    for(int i =0; i< n ; i++ ) {
        int tmp;
        cin>>tmp;
        tmp = rec[tmp];
        mp[tmp]++;
    }

    vector<pii>vec;

    for(auto x : mp) vec.push_back(x);
    vector<int>ans(n, -1);

    int cnt = 0;
    while(1) {


        // for(auto x : vec) cout<<x.uu<<" "<<x.vv<<"\n";
        // cout<<'\n';

        for(auto x : vec) ans[cnt] = max(ans[cnt], x.vv);
        
        mp.clear();

        for(auto x : vec) {

            if(x.vv %2 == 0) mp[1] += x.vv;
            else mp[x.uu] += x.vv;
        }

        vector<pii>rec;
        for(auto x : mp) rec.push_back(x);

        if(rec == vec) break;

        vec = rec;

        cnt++;
    }




    int q;
    cin>>q;
    while(q--) {
        ll tmp;
        cin>>tmp;

        if(tmp <=cnt) cout<<ans[tmp]<<'\n';
        else cout<<ans[cnt]<<'\n';
    }

}


int main()  {
    fastio;

    seive();

    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}