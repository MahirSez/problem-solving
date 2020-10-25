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
int n;
int typ[N] , val[N] , ara[N];

bool ok() {
    set<int>ss;
    int id = 1;

    for(int i =0 ; i < n ; i++ ) {
       if(typ[i] == 1)  {
           ss.insert(ara[id]);
           id++;
       }
       else {
           int vall = *ss.begin();
           ss.erase(vall);
           if(vall != val[i]) return 0;
       }
    }
    return 1;
}

int main()  {
    fastio;
    
    cin>>n;
    n += n;
    for(int i =0 ; i <n ; i++ ) {
        string s;
        cin>>s;
        if(s == "+") typ[i] = 1;
        else {
            typ[i] = -1;
            cin>>val[i];
        }
    }

    int tot = 0;
    for(int i =0 ; i < n ; i++ ) {
        tot += typ[i];
        if(tot < 0) {
            cout<<"NO\n";
            return 0;
        }
    }

    int till = 0;
    set<int>av;


    for(int i =0 ; i < n ; i++ ) {
        if(typ[i] == 1) {
            till++;
            av.insert(till);
        }
        else {
            int id = *av.rbegin();
            av.erase(id);
            ara[id] = val[i];
        }
    }

    if(!ok()) {
        cout<<"NO\n";
        return 0;
    }

    cout<<"YES\n";
    for(int i =1 ; i <=n/2 ; i++ ) cout<<ara[i]<<" ";
    cout<<'\n';
    return 0;


    
    
}