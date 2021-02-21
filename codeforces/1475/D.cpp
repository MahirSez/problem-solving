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
        vector<ll>aval , bval, vec(n) , typ(n);
        for(int i =0; i <n; i++ ) cin>>vec[i];
        for(int i =0; i <n; i++ ) cin>>typ[i];
        for(int i =0 ;i <n ; i++ ) {
            if(typ[i] == 1) aval.push_back(vec[i]);
            else bval.push_back(vec[i]);
        }

        sort(aval.rbegin() , aval.rend());
        sort(bval.rbegin() , bval.rend());

        int cnt = 0;
        ll taken = 0;

        ll loss = 0;

        for(auto x : bval) {
            if(taken >= m) break;
            taken += x;
            cnt++;
            loss +=2;
        }
        while(bval.size() > cnt) bval.pop_back();
        int till = -1;

        for(auto x : aval) {
            if(taken >= m) break;
            till++;
            taken += x;
            loss++;
        }
        ll ansloss = INF;
        if(taken >= m) ansloss = loss;


        while(1) {
            if(bval.size() == 0) break;
            loss -= 2;
            taken -= bval.back();
            bval.pop_back();

            while(1) {
                if(taken >= m || till == aval.size()-1) break;
                till++;
                taken += aval[till];
                loss++;
            }
            if(taken >= m ) ansloss = min(ansloss , loss);
        }
        if(ansloss == INF ) ansloss = -1;
        cout<<ansloss<<'\n';
    }
    return 0;
}