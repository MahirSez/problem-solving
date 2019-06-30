#include<bits/stdc++.h>
#define pii pair<int,int>
#define uu first
#define vv second

using namespace std;
int ara[3000] , par[3000];
vector<pii>one , zero;
int n,m;


int boss(int x) {
    return (par[x] == x) ? x : (par[x] =  boss(par[x]) )  ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    
    for(int i = 1;  i <= n ; i++ ) par[i] = i;
    
    for(int i= 0 ; i < m ; i++ ) {
        int typ , frm ,to;
        cin>>typ>>frm>>to;
        if( typ ) one.push_back({frm,to});
        else zero.push_back({frm,to});
    }
    
    for(auto x : one) {
        int frm = x.uu;
        int to = x.vv;
        
        
        for(int i = to  ; i <= n ; i++ ) {
            if(boss(i) == boss(to)) to = i;
        }
        for(int i = frm  ; i <=to ; i++ ) {
            par[i] = boss(frm);
        }
    }
    
    for(auto x : zero) {
        int frm = x.uu;
        int to = x.vv;
        int parF = boss(frm);
        int parT = boss(to) ;
        if(parF == parT) {
            cout<<"NO\n";
            return 0;
        }
        int key = -1;
        for(int i = frm ;  i<=to ; i++ ) {
            if(boss(i) != boss(frm) ) {
                key = i;
                break;
            }
        }
        assert(key != -1);
        for(int i = key ; i <= n ; i++ ) {
            ara[i]--;
        }

    }
    int mn = 1e9;
    
    for(int i = 1 ; i <= n ; i++ ) mn = min(mn , ara[i]);
    
    int off =  1 - mn;
    cout<<"YES\n";
    
    for(int i =1 ; i <= n ; i++ ) {
        cout<<ara[i]+ off <<" ";
    }
    cout<<'\n';
    return 0;
}