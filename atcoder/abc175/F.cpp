#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pip         pair<int,pii>
#define pll         pair<ll,ll>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

typedef tuple<ll, int ,int ,int> tp;

const int N = 110;
string s[N];
ll n , dist[N][N][2] , cst[N];
ll ans = INF;

bool isPal(string tgt) {
    
    string tmp = tgt;
    reverse(tmp.begin() , tmp.end());
    return tmp == tgt;
}


void dijk() {

    priority_queue<tp , vector<tp> , greater<tp> > pq;

    for(int i =0 ; i < n ; i++ ) {

        dist[ i ] [s[i].size() ][1] = min( dist[ i ][ s[i].size() ][1], cst[i]);
        pq.push({cst[i] , i , s[i].size() , 1} );
    }

    while(!pq.empty()) {
        ll id , val , len , side;
        tie(val , id , len , side) = pq.top();
        pq.pop();

        // cout<<id<<" "<<val<<" "<<len<<" "<<side<<'\n';


        if(val != dist[id][len][side]) continue;

        string tgt = "";

        for(int i = 0 ; i < len && side == 0; i++ ) tgt += s[id][i];
        for(int i = 0 , j = s[id].size() - 1 ; i < len && side ;i++ , j-- ) tgt += s[id][j];

        if(side) reverse(tgt.begin() , tgt.end());

        // cout<<id<<" -- "<<side<<" -- "<<tgt<<'\n';
        if(isPal(tgt)) {
            ans = min(ans , val);
            continue;
        }

        


        for(int i =0 ; i < n ; i++ ) {
            
            int cnt = 0;

            for(int j = len-1 , k = 0 ;side == 0 && j >=0 && k < s[i].size() && tgt[j] == s[i][k] ; j-- , k++) cnt++;

            for(int j = 0 , k = s[i].size() -1 ; side && j < len && k >= 0 && tgt[j] == s[i][k] ; j++ , k--) cnt++;


            //// cout<<" "<<i<<" "<<cnt<<'\n';

            if(cnt == len ) {
                
                ll nwval = val + cst[i];
                ll nwlen = s[i].size() - cnt;
                ll nwside = side ^1;

                if(dist[i][nwlen][nwside] > nwval) {
                    dist[i][nwlen][nwside] = nwval;
                    pq.push({nwval , i , nwlen , nwside});
                }
            }
            else if(cnt == s[i].size()) {
                ll nwval = val + cst[i] ;
                ll nwlen = len - cnt;
                ll nwside = side;

                if(dist[id][nwlen][nwside] > nwval) {
                    dist[id][nwlen][nwside] = nwval;
                    pq.push({nwval , id , nwlen , nwside});
                }
            }

        }

    }

}


int main()  {
    fastio;
    
    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>s[i]>>cst[i];

    for(int i =0 ; i < N ; i++ ) {

        for(int j =0 ; j < N ; j++ ) dist[i][j][0] = dist[i][j][1] = INF;
    }

    dijk();
    cout<<(ans >= INF ? -1 : ans)<<'\n';
    return 0;
}