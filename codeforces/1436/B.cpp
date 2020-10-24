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

const int N = 200;
int ara[200][200];

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199};
int is_prm[305];

int main()  {
    fastio;
    int m = 46;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i =1 ; i <= n ; i++ ) {
            for(int j =1 ; j <=n ; j++ ) ara[i][j] = 1;
        }

        int tgt = -1;
        for(int i =0 ; i < m ; i++ ) is_prm[primes[i]] = 1;

        for(int i =0 ; i < m; i++ ) {
            if(primes[i] >= n-1 && is_prm[primes[i] - (n-1)] == 0 ) {
                tgt = primes[i] - (n-1);
                break;
            }
        }
        assert(tgt != -1);

        for(int i =1; i <=n ; i++ ) {
            for(int j =1 ; j <= n ; j++) {
                if(i == j) ara[i][j] = tgt;
                cout<<ara[i][j]<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
    
}