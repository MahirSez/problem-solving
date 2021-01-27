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

    int q;
    cin>>q;

    vector<int>vis(N);

    queue<pii>qq ;
    priority_queue<pii>pq;
    int id = 1;

    while(q--) {

        int typ;
        cin>>typ;

        if(typ == 1) {
            int val;
            cin>>val;
            qq.push({val, id});
            pq.push({val, -id});
            id++;
            continue;
        }

        if(typ == 2) {
            while(1) {
                pii top = qq.front();
                if(vis[top.vv]) qq.pop();
                else break;
            }
            pii top = qq.front();
            qq.pop();
            vis[top.vv] = 1;
            cout<<top.vv<<" ";
            continue;
        }
        if(typ == 3) {
            while(1) {
                pii top = pq.top();
                top.vv *=-1 ;
                if(vis[top.vv]) pq.pop();
                else break;
            }
            pii top = pq.top();
            pq.pop();
            top.vv *=-1 ;
            vis[top.vv] = 1;
            cout<<top.vv<<" ";
            continue;
        }        
    }
    cout<<'\n';
    return 0;
}