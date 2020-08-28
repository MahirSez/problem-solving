#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int main()  {
    fastio;
    int n;
    cin>>n;
    vector<int>vec;

    while(n) {

        int tmp = n;

        int tgt = 0;
        int ten = 1;

        while(tmp) {
            if(tmp%10) tgt+= ten;
            tmp /= 10;
            ten *=10;
        }
        vec.push_back(tgt);
        n -=tgt;

    }
    cout<<vec.size()<<'\n';
    for(auto x : vec) cout<<x<<" ";
    cout<<'\n';
}  