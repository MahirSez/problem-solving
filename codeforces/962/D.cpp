#include <bits/stdc++.h>
#define ll          long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
struct info {
    ll val ;
    int id ;
}ara[MAX];

struct pqComp {

    bool operator() ( const info& a , const info& b ) {
        if( a.val==b.val)
            return (a.id> b.id);
        return (a.val > b.val);
    }
};

bool comp(const info& a ,const info& b) {
    return (a.id < b.id);
}

int n, cnt;
map<ll,int>mp;
vector<info>edg[MAX];
vector<info>ans;

void solve(int id) {

    priority_queue<info, vector<info> , pqComp >pq;
    for(int i =0  ; i < edg[id].size() ; i++) {
        pq.push(edg[id][i]);
//        cout<<edg[id][i].val<<" ";
    }
//    cout<<endl<<endl;

//    while( !pq.empty() ) {
//        cout<<pq.top().val<<" "<<pq.top().id<<endl;
//        pq.pop();
//    }
//    return;
    while( !pq.empty() ) {

        info top = pq.top();
//        cout<<top.val<<" "<<top.id<<endl;
        pq.pop();

        if( pq.empty() ) {
            ans.push_back(top);
            break;
        }

        info nwtop = pq.top();
        if( top.val == nwtop.val ) {

            info nw;
            nw.val = nwtop.val * 2;
            nw.id = nwtop.id;
            pq.pop();
            pq.push(nw);
        }
        else {
            ans.push_back(top);
        }
    }
}

int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        cin>>ara[i].val;
        ara[i].id = i;
    }

    for(int i =0 ; i < n ; i++) {

        ll tmp = ara[i].val;
        while( !(tmp&1) ) {
            tmp/=2;
        }
        if( mp[tmp] == 0 ) {
            mp[tmp] = ++cnt;
            edg[cnt].push_back(ara[i]);
        }
        else edg[mp[tmp]].push_back(ara[i]);

    }
//    map<int,int>::iterator it;
//    for(it = mp.begin() ; it != mp.end() ;it++ ) {
//        int id = it->vv;
//        cout<<it->uu<<" ftft ";
//        for(int i =0 ; i < edg[id].size() ; i++ )
//            cout<<edg[id][i].val<<" ";
//        cout<<endl;
//    }
    for(map<ll,int>::iterator it =mp.begin();it !=mp.end() ; it++ ) {

        int id = it->vv;

        solve(id);
    }

    sort( ans.begin() , ans.end() , comp);
    cout<<ans.size()<<endl;
    for(int  i=0 ;i < ans.size() ; i++ )
        cout<<ans[i].val<<" ";
    cout<<endl;
    return 0;

}
