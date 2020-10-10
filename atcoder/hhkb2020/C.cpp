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
int taken[N];

int main()  {
    fastio;

    set<int>ms;
    for(int i =0 ; i < N ; i++ ) ms.insert(i);

    int n;

    cin>>n;
    while(n--) {
        int tmp;
        cin>>tmp;
        if(taken[tmp]==0) {
            ms.erase(tmp);
            taken[tmp] = 1;
        }
        cout<<*ms.begin()<<'\n';
    }
    return 0;
    
}   