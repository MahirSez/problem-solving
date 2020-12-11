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
        int n, m;
        cin>>n>>m;
        vector<int>vec(n+1);
        vector<double>prob(n+1, 1.0);
        for(int i =1; i <=n ; i++ ) cin>>vec[i];

        while(m--) {
            int r;
            double x;
            cin>>r>>x;
            prob[r] *= (1 - x);
        }

        for(int i =1 ; i <=n ; i++ ) {
            prob[i] = 1- prob[i];
        }
        // for(int i = 1 ; i <=n ; i++ ) cout<<prob[i]<<" ";
        // cout<<'\n';



        double ans = 0.0;
        double now = 1;

        for(int i = n ; i >=1 ; i--) {
            
            ans += prob[i] * now;
            now *= (1-prob[i]);

            if(vec[i] != i) break;
        }

        vector<int>tmp = vec;
        sort(tmp.begin() , tmp.end());
        if(tmp == vec) cout<<1<<'\n';
        else cout<<setprecision(10)<<fixed<<ans<<'\n';

        
    }
    return 0;
}

/*
1
4 3
4 3 2 1
1 0.3
3 1
4 0.6
*/