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
 
int main() {
    fastio;
    int n;
    cin>>n;
    vector<int>fre(n+3);
    for(int i =0 ; i < n ; i++ ) {
        int tmp;
        cin>>tmp;
        fre[tmp]++;
    }
    int mn = 0;
 
    for(int i =1 ; i <=n ; i++ ) {
        if(fre[i] ) {
            mn++;
            i += 2;
        }
    }
 
    for(int i = 1 ; i <= n ; i++ ) {
        if(fre[i] && fre[i-1] == 0) {
            fre[i]--;
            fre[i-1]++;
        }
    }
    for(int i = n ; i >=1 ; i--) {
        if(fre[i] && fre[i+1] == 0) {
            fre[i+1]++;
            fre[i]--;
        }
    }
 
    int mx = 0;
    for(auto x : fre) mx += (x > 0);
    cout<<mn<<" "<<mx<<'\n';
    return 0;
}