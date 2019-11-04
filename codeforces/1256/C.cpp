#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e4 + 4;
int n , m , d;
int ara[MAX] , len[MAX] , pos[MAX];

void print() {
    
    for(int i =1; i<=n ; i++ ) cout<<ara[i]<<" ";
    cout<<'\n';
}

int main()
{
    fastRead;
    cin>>n>>m>>d;
    for(int i =1; i <=m ; i++ ) cin>>len[i];
    
    int now = n , id = m;
    
    while(id>0) {
        
        for(int i= 0 ; i < len[id] ; i++ ) {
            ara[now] = id;
            pos[id] = now;
            now--;
        }
        id--;
    }
    
//    for(int i =1; i <=m ; i++ ) cout<<pos[i]<<" ";
//    cout<<'\n';;
    
    now = 0;
    bool ok = true;
    id = 1;
    
    while(now <= n ) {
        
        if(now + d > n || ara[now+d] ) break;
        
        if(id > m) {
            ok = false;
            break;
        }
        
        
        
        for(int i = 1  , j = pos[id]; i <= len[id] ; i++ , j++) {
            ara[j] = 0;
        }
        

        int frm = now + d;
        
        int tgt = len[id];
//        cout<<frm<<" "<<tgt<<'\n';
    
        
        for(int i = 1 ,j = frm ; i <= len[id] && ara[j] == 0 ; i++, j++ ) {
            
            ara[j] = id;
            tgt--;
            now = j;
        }
        
//        if(id == 2) {
//            print();
//            cout<<now<<'\n';
//            return 0;
//        }
        while(tgt > 0 ) {
        
            ara[--frm] = id;
        }
//        print();
        id++;
    }
    
    if(!ok) {
        cout<<"NO\n";
        return 0;
    }
    
    cout<<"YES\n";
    for(int i= 1 ; i <= n ; i++ ) cout<<ara[i]<<" ";
    cout<<'\n';
    return 0;
}