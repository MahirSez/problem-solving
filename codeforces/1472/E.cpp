#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define ppi         pair<pii,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

bool comp(const ppi &p1, const ppi &p2) {
    if(p1.uu ==p2.uu) return p1.vv < p2.vv;

    if(p1.uu.vv == p2.uu.vv) return p1.uu.uu < p2.uu.uu;
    return p1.uu.vv < p2.uu.vv;
}


int main()  {
    fastio;

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<ppi>vec(n);
        vector<int>ans(n, -1);

        set<ppi>st;

        for(int i =0; i < n ; i++ ) {
            int u , v, id;
            cin>>u>>v;
            id = i;

            if(u > v) swap(u,v);

            st.insert({{v, u}, i});

            vec[i] = {{v , u} , i};
        }

        sort(vec.begin() , vec.end(), comp);

        // for(auto x : vec) {
        //     cout<<x.uu.vv<<" "<<x.uu.uu<<" "<<x.vv<<'\n';
        // }



        for(int i =0 ;i <n ; i++ ) {
            vector<ppi>tmp;

            for(int j = i ; j < n ; j++ ) {
                if(vec[j].uu.vv == vec[i].uu.vv) {
                    tmp.push_back(vec[j]);
                    i = j;
                }
                else break;
            }

            for(auto x : tmp) st.erase(x);

            if(tmp.size() ==0) continue;


            int id = tmp[0].vv;
            int val = tmp[0].uu.uu ;


            while(st.size() > 0) {

                ppi tmp = *st.rbegin();

                if(tmp.uu.uu > val) {
                    ans[tmp.vv] = id+1;
                    st.erase(tmp);
                }
                else break;
            }
        }

        assert(st.size() == 0);
        for(auto x : ans) cout<<x<<" ";
        cout<<'\n';

    }
    return 0;
}