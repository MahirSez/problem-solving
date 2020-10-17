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
vector<int>rec[N];
queue<int>q[5];

set<int>av;

void dump() {
    cout<<-1<<'\n';
    exit(0);
}

int get() {
    if(av.size() ==0 ) dump();
    int id = *av.begin();
    av.erase(id);
    return id;
}

int main()  {
    fastio;
    int n;
    cin>>n;
    
    for(int i =1; i <=n ; i++ ) av.insert(i);

    vector<int>vec(n+1) , fre(n+1);
    for(int i =1 ; i <= n ; i++  ) {
        cin>>vec[i];
        q[vec[i]].push(i);
    }

    for(int i =1 ; i <=n ; i++ ) {

        for(int j =1 ; j <=3 ; j++ ) {
            while(!q[j].empty() && q[j].front() <= i ) q[j].pop();
        }

        if(vec[i] == 0) continue;

        if(vec[i] == 1) {

            if(rec[i].size() )  continue;
            int id = get();
            rec[i].push_back(id);
            continue;
        }

        if(vec[i] == 2) {
            int rid = -1;
            if(rec[i].size() == 0) {
                rid = get();
                rec[i].push_back(rid);
            }
            else if(rec[i].size() == 2) rid = max(rec[i][0] , rec[i][1]);
            else assert(0);

            if(q[1].empty()) dump();
            int cid = q[1].front();
            q[1].pop();
            rec[cid].push_back(rid);

            continue;
        }

        
        int rid1 = -1;

        if(rec[i].size() == 0 ) {
            rid1 = get();
            rec[i].push_back(rid1);
        }
        else if(rec[i].size() == 2) rid1 = max(rec[i][0] , rec[i][1]);
        else assert(0);

        if(av.size() == 0 ) dump();
        auto it = av.lower_bound(rid1+1);
        if(it == av.end()) dump();

        int rid2 = *it;
        av.erase(rid2);

        int ok = 0;

        

        for(int j = 3;  j >=1 ; j--) {

            if(q[j].empty()) continue;
            ok = 1;

            int cid = q[j].front();
            q[j].pop();
            rec[cid].push_back(rid1);
            rec[cid].push_back(rid2);
            break;
        }

        if(!ok)  dump();
        
    }

    vector<pii>ans;
    for(int i =1; i <=n ; i++ ) {
        assert(rec[i].size() <= 2) ;
        for(auto x : rec[i]) {
            ans.push_back({i , x});
            fre[x]++;
        }
    }
    for(int i =1 ; i <=n ; i++ ) assert(fre[i] <= 2);
    cout<<ans.size()<<'\n';
    for(auto x : ans) cout<<x.vv<<" "<<x.uu<<'\n';
    return 0;


}