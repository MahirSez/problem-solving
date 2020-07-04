#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int dx[]= {0,0, -1, 1};
int dy[] = {1, -1, 0, 0};
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n, m;
        cin>>n>>m;
        
        vector< vector<int> > vec(n, vector<int>(m));
        int ok = 1;
        for(int i =0 ; i < n ; i++) {
            for(int j =0 ; j < m ; j++ ) {
                
                int cnt = 0;
                for(int k =0 ; k < 4; k ++ ) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    if(xx >=0 && xx< n && yy>= 0 && yy < m) cnt++;
                }
                int tmp;
                cin>>tmp;
                if(tmp > cnt) ok = 0;
                vec[i][j] = cnt;
            }
        }
        if(!ok) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(auto x : vec) {
            for(auto xx: x) {
                cout<<xx<<" ";
            }
            cout<<'\n';
        }
    }
    return 0;
}