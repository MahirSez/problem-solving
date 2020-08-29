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
    int n;
    cin>>n;
    vector<int>vec(n) , fre(N);
    for(int i = 0 ; i < n ; i++ ) {
        cin>>vec[i];
        fre[vec[i]]++;
    }

    int gcd = vec[0];

    for(auto x : vec) {
        gcd = __gcd(x , gcd);
    }
    if(gcd !=1) {
        cout<<"not coprime\n";
        return 0;
    }
    // for(auto x : fre) {
    //     if(x> 1) {
    //         cout<<"setwise coprime\n";
    //         return 0;
    //     }
    // }

    for(int i =2 ; i < N ; i++ ) {
        int tot = 0;
        for(int j = i ; j < N ; j += i) {
            tot += fre[j];
        }
        if(tot > 1) {
            cout<<"setwise coprime\n";
            return 0;
        }
    }
    cout<<"pairwise coprime\n";
    return 0;

    
    
}