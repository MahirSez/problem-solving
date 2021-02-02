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

bool check(int n, int d) {
    while(n) {
        if(n%10 == d) return 1;
        n/= 10;
    }
    return 0;
}

int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        int n , d;
        cin>>n>>d;

        while(n--) {

            int tmp;
            cin>>tmp;
            int ok = 0;
            while(!ok && tmp >= d )  {

                ok |= check(tmp, d);
                tmp -= d;
            }
            cout<<(ok? "YES" : "NO")<<'\n';
        }
    }
    return 0;

}