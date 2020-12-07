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
int ara[400][400];
int n;


void print() {

    for(int i = 0; i < n ; i++ ) {
        for(int j =0; j < n; j++ ) {
            if(ara[i][j] == 0) cout<<'O';
            else if(ara[i][j] == 1) cout<<'X';
            else cout<<'.';
        }
        cout<<'\n';
    }

}


int main()  {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        
        cin>>n;
        int cnt1 = 0;
        for(int i =0; i < n;i++ ) {
            string s;
            cin>>s;
            for(int j =0; j < n;j++ ) {
                if(s[j] == 'O') ara[i][j] = 0 , cnt1++;
                else if(s[j] == 'X') ara[i][j] = 1 , cnt1++;
                else ara[i][j] = -1;
            }
        }
        vector<int>fre(5);
        for(int i =0 ; i <n ; i++ ) {
            for(int j =0 ; j < n; j++ ) {
                if(ara[i][j]==1) fre[(i+j)%3]++;
            }
        }

        int tgt_col = -1;
        for(int i= 0 ; i < 3 ; i++ ) {
            if(fre[i] <= cnt1/3) tgt_col = i;
        }

        assert(tgt_col != -1);
        for(int i =0 ; i < n ;i++ ) {
            for(int j =0 ; j < n ; j++ ) {
                if(ara[i][j] == 1 && (i+j)%3 == tgt_col) ara[i][j] = 0;
            }
        }
        print();
        

    }
    return 0;
}