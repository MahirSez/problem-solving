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
int n, m;
int ara[1000][1000], ans[1000][1000];
int rec[20];
int main()  {
    fastio;
    cin>>n>>m;

    for(int i =0; i< n ; i++ ) {
        for(int j =0; j < m; j++) cin>>ara[i][j], ans[i][j] = 720720;
    }

    vector<int>tmp;
    for(int i =1 ; i <= 30 ; i++ )  {
        tmp.push_back(i*i*i*i);
    }


    for(int i = 1 ; i <= 16 ; i++ ) {
        int ok = 0;
        for(auto x : tmp) {
            if(720720 - x >= i && (720720 - x) %i == 0) {
                ok = 1;
                rec[i] = 720720 - x;
                break;
            }
        }

        assert(ok);
    }



    for(int i =0 ; i <n ; i++ ) {
        for(int j =0; j < m ; j++ ) {
            if( (i + j)%2 ) {
                cout<<720720<<" ";
            }
            else cout<<rec[ara[i][j]]<<" ";
        }
        cout<<'\n';
    }
    return 0;

    
}