#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("input.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("output.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m;
int ara[2000][2000] ;
pii rec[2000][2000] ;
map<pii,int>mark;
ll ans = 0;


void solve() {

    pii lastMid = {-1,-1};
    pii lastTop = {-1, -1};
    pii lastDown = {-1, -1};
    
    int cur = 0;
    
    for(int i =0 ; i < n ; i++ ) {
        
        for(int j =0 ; j < m ; j++ ) {
            
            
            if(mark[{i,j}]) {
                lastMid = {-1, -1};
                lastTop = {-1, -1};
                lastDown = {-1, -1};
                continue;
            }
            
            int midCol = rec[i][j].uu;
            int midH = rec[i][j].vv;
            
//            cout<<i<<" "<<j<<" "<<midCol<<" "<<midH<<endl;
            
            
            
            int topCol = -1 , topH = 0;
            int downCol = -1 , downH = 0;
            
            for(int k = i ; k>=0 ; k--)  {
                
                if(rec[i][j] != rec[k][j]) {
                    topCol = rec[k][j].uu;
                    topH = rec[k][j].vv;
                    break;
                }
                mark[{k,j}] =1;
            }
            
            for(int k = i ; k < n ; k++ ) {
                
                if(rec[i][j] != rec[k][j]) {
                    downCol = rec[k][j].uu;
                    downH = rec[k][j].vv;
                    break;
                }
                mark[{k,j}] =1;
            }
            
            if( topCol == -1 || downCol == -1 ) {
                lastMid = {-1, -1};
                lastTop = {-1, -1};
                lastDown = {-1, -1};
                continue;
            }
            
            topH = min(topH , midH);
            downH = min(downH , midH);
            
            pii nowTop = {topCol , topH};
            pii nowDown = {downCol , downH};
            pii nowMid = {midCol , midH};
            
            if(topH != midH || midH != downH ) {
                cur = 0;
                
                lastMid = {-1, -1};
                lastTop = {-1, -1};
                lastDown = {-1, -1};
                continue;
            }
            
//            cout<<i<<" "<<j<<"---"<<midH<<endl;
//            
//            cout<<nowMid.vv<<" "<<lastMid.vv<<endl;
            
            if( nowTop == lastTop && nowDown == lastDown && nowMid== lastMid) {
                cur++;
            }
            else {
                cur = 1;
                lastMid = nowMid;
                lastTop = nowTop;
                lastDown = nowDown;
            }
            
            ans += cur;
            
            
        }
    }

}


void pre() {

    
    for(int j =0 ; j < m ; j++ ) {
        
        for(int i =0 ; i < n ; i++ ) {
            
            int cnt = 0;
            int k = i;
            for(k = i ; k < n ; k++ ) {
                
                if(ara[i][j] == ara[k][j] )cnt++;
                else  break;
            }
            
            pii tmp = {ara[i][j] , cnt};
            
            for(int kk =  i ; kk  < k  ; kk++ ) {
                rec[kk][j] = tmp;
            }
            i = k-1;
        }
        
        
//        for(int i =0 ; i < n ; i++ ) {
//            cout<<rec[i][j].vv<<" ";
//        }
//        cout<<endl;
    }
//    cout<<endl;
    

}


int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < n ; i++ ) {
        string str;
        cin>>str;
        for(int j =0 ; j < m ; j++ ) {
            ara[i][j] = str[j] - 'a';
        }
    }
    
    pre();
    
    
    solve();
    
    cout<<ans<<endl;
    return 0;
    
}

/*

6 3
aaa
aaa
bab
bbb
ccc
ccc
*/
