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
        int tot = 0;
        vector<int> cntX(3) , cntO(3);
        for(int i =0; i < n;i++ ) {
            string s;
            cin>>s;
            for(int j =0; j < n;j++ ) {
                if(s[j] == 'O') ara[i][j] = 0 , cntO[(i+j)%3]++ , tot++;
                else if(s[j] == 'X') ara[i][j] = 1 , cntX[(i+j)%3]++ , tot++;
                else ara[i][j] = -1;
            }
        }
        
        int ok = 0;

        for(int i =0 ; i < 3 and !ok; i++ ) {
            for(int j =0 ; j < 3 and !ok; j++ ) {
                if(i == j) continue;

                if(cntX[i] + cntO[j] > tot/3) continue;
                ok = 1;

                for(int ii =0 ; ii < n ; ii++) {
                    for(int jj = 0; jj < n ; jj++ ) {

                        if((ii+jj)%3 == i && ara[ii][jj] == 1) ara[ii][jj] = 0;
                        if((ii+jj)%3 == j && ara[ii][jj] == 0) ara[ii][jj] = 1;

                    }
                }
            }
        }
        assert(ok);
        print();
        

    }
    return 0;
}