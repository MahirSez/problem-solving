#include <bits/stdc++.h>
#define pii pair<int,int>
#define uu first
#define vv second
#define ll long long int
#define fastio 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6+6;
const ll INF = 1e9;

typedef tuple<ll , int , int , int > tp;

int n , m , par[MAX];
vector<tp>edgList , cpy;

int boss(int x) {
    if( par[x] == x) return x;
    return par[x] = boss(par[x]);
}

int mst() {

    for(int i = 1 ; i<=n ; i++ )  par[i] = i;

    sort( edgList.begin() , edgList.end() );
    
    for(auto x : edgList) {
        ll val , id,  u , v;
        tie(val , id , u , v) = x;
        int parU = boss(u);
        int parV = boss(v);
        if( parU != parV ) {
            par[parU] = parV;
            if(id == 0) return 1;
        }
    }
    return  0;
}


int main()
{
    fastio;
    cin>>n>>m;
    for(int i =0 ; i < m ; i++) {
        int u , v , w;
        cin>>u>>v>>w;
        edgList.push_back({w , i , u,v });
    }
    cpy = edgList;

    ll lo = 0 , hi = INF , ret = -1;


    while(lo <=hi ) {
        ll mid = (lo+hi)/2;

        edgList = cpy;
        get<0>(edgList[0]) = mid;
        
        if(mst()) {
            ret = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }



    cout<<ret<<'\n';
    return 0;
}
