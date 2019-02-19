#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000006
using namespace std;
int n ;
vector<int>edg[MAX];
int col[MAX];
int totRed , totBlu;
int Rchild[MAX] , Bchild[MAX];
int ans;

void dfs1(int node , int par) {

    if( col[node] == 1) Rchild[node]++;
    else if( col[node] == 2) Bchild[node]++;

    for( auto x : edg[node]) {

        if( x == par) continue;
        dfs1(x,  node);
        Rchild[node] += Rchild[x];
        Bchild[node] += Bchild[x];   
    }

}


void dfs2(int node , int par) {

    for(auto x : edg[node]) {
        if( x == par) continue;

        if(totRed == Rchild[x] && Bchild[x] ==0) ans++;
        else if( totBlu == Bchild[x] && Rchild[x] ==0) ans++;
        dfs2(x , node);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i = 1 ; i <= n ; i++ ) {
        cin>>col[i];
        if( col[i] == 1 ) totRed++;
        else if( col[i] == 2) totBlu++;
    }

    for(int i =0 ; i < n-1 ; i++ ) {
        int u , v;
        cin>>u>>v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }

    dfs1(1 , 0 );
    
    dfs2(1, 0);
    cout<<ans<<endl;
    // for(int i =1 ; i <= n; i++ ) {
    //     cout<<Rchild[i]<<" "<<Bchild[i]<<endl;
    // }

}