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

vector<pii>rec;
int n;

void solve(int frm , int to , int pw) {

    for(int i =0 ; i <= pw ; i++) {

        vector<int>taken(n+1);

        for(int j = frm ; j + (1<<i) <=to ; j++ ) {
            if(taken[j]) continue;
            taken[j] = 1;
            taken[j + (1<<i)] = 1;
            rec.push_back({ j, j + (1<<i) });
        }
    }
}
  
int main() {
    fastio;
    
    cin>>n;
    int pw = -1;
    for(int i =0 ; i <=n ; i++ )  {
        if( (1<<i) > n) {
            pw = i-1;
            break;
        }
    }

    solve(1 , (1<<pw), pw );
    int f = n - (1<<pw) + 1;
    solve(f , n ,pw);

    cout<<rec.size()<<'\n';
    for(auto x : rec) cout<<x.uu<<" "<<x.vv<<'\n';

    return 0;
}