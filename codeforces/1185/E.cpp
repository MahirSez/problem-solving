#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int t  , n , m , ara[3000][3000] , cnt[30];
int one;

pii lup[30] , rdn[30] ,oneup , onedn;


void reset() {

    memset(lup , -1 , sizeof lup);
    memset(rdn , -1 , sizeof rdn);
//    memset(ans , -1 , sizeof ans);
    oneup = {-1,-1};
    onedn = {-1,-1};
    one = 0;
    memset(cnt , 0 , sizeof cnt);
}


bool goHor(int id , int frm , int to , int ro) {

    
    int f  = frm  , t = to;
    
    for(int col =frm ; col < m ; col++ ) {
        
         if(ara[ro][col] != id && ara[ro][col] != -1) {
            if( col <= to ) return false;
            break;
         }
        
        
        t = max(col , t);
        ara[ro][col] = -1;
    }
    for(int col = frm ; col >=0 ; col-- ) {
        
        if( ara[ro][col] != -1) break;
        
        f = min(f , col) ;
    }
    
    lup[id] = {ro , f};
    rdn[id] = {ro , t};
    if( t-f+1 > one) {
        one = t - f + 1;
        oneup = lup[id];
        onedn = rdn[id];
    }
    
    return true;
}

bool goVer(int id , int frm , int to , int col) {

    
    int f  = frm  , t = to;
    
    for(int ro =frm ; ro < n ; ro++ ) {
        
        if(ara[ro][col] != id && ara[ro][col] != -1) {
            if( ro <= to ) return false;
            break;
        }
        
        t = max(ro , t);
        ara[ro][col] = -1;
    }
    for(int ro = frm ; ro >=0 ; ro-- ) {
        
        if( ara[ro][col] != -1) break;
        
        f = min(f , ro) ;
    }
    
    lup[id] = {f , col};
    rdn[id] = {t , col};
    if( t-f+1 > one) {
        one = t - f + 1;
        oneup = lup[id];
        onedn = rdn[id];
    }
    return true;
}

void ThirdCheck(int ro , int col , int id) {

    
    int f1 = ro  ,t1 = ro;
    int f2 = col  ,t2 = col;
    
    ara[ro][col] = -1;
    
    for(int i = f1 ; i < n ; i++ ) {
        if( ara[i][col] == -1)  t1 = i;
        else break;
    }
    
    for(int i = f1 ; i>= 0 ; i--) {
        if( ara[i][col] == -1)  f1 = i;
        else break;
    }
    int len1 = t1 - f1 +1;
    
    for(int i  = f2 ; i < m ; i++ ) {
        if( ara[ro][i] == -1) t2 = i;
        else break;
    }
    
    for(int i  = f2 ; i >= 0 ; i-- ) {
        if( ara[ro][i] == -1) f2 = i;
        else break;
    }
    
    int len2= t2 - f2 + 1;
    
    if( len2 > len1) {
        
        lup[id] = {f1 , col};
        rdn[id] = {t1 , col};
        
        one = len2;
        oneup = lup[id];
        onedn = rdn[id];
    }
    else {
        
        lup[id] = {ro , f2};
        rdn[id] = {ro , t2};
        
        one = len1;
        oneup = lup[id];
        onedn = rdn[id];
    }
}


void secondCheck(int id) {

    lup[id] = oneup;
    rdn[id] = onedn;
    
}



int solve(int id) {
    
    
    
    
    for(int i= 0 ; i < n ; i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            if( ara[i][j] != id) continue;
            
            
            if( lup[id] == pii(-1,-1) ) lup[id] = {i,j};
            if( rdn[id] == pii(-1,-1)) lup[id] = {i,j};
            
            lup[id] = min(lup[id] , {i,j});
            rdn[id] = max(rdn[id] , {i,j});
        }
    }
    
    
    
    
    if(lup[id] == pii(-1,-1)) {
        secondCheck(id);
        return true;
    }
//    cout<<id<<" "<<lup[id].uu<<" "<<lup[id].vv<<"  "<<rdn[id].uu<<" "<<rdn[id].vv<<endl;
    
    if( lup[id].uu != rdn[id].uu && lup[id].vv != rdn[id].vv) {
        return false;
    }
    
    if( lup[id] == rdn[id]) {
        ThirdCheck(lup[id].uu , lup[id].vv , id);
        return true;
    }
    
    if( lup[id].uu == rdn[id].uu ) {
        
        return goHor(id , lup[id].vv , rdn[id].vv , lup[id].uu);
    }
    else if(lup[id].vv == rdn[id].vv ) {
        
        return goVer(id , lup[id].uu , rdn[id].uu , rdn[id].vv);
    }

    
}


void print() {

    for(int i =0 ; i < n ; i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            cout<<ara[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
} 




int main()
{
    fastRead;
    cin>>t;
    while( t-- ) {
        
        cin>>n>>m;
        reset();
        
        for(int i =0 ; i < n ; i++ ) {
            string str;
            cin>>str;
            for(int j =0 ; j < m ; j++ ) {
                if( str[j] == '.') ara[i][j] = 0;
                else {
                    ara[i][j] = (str[j]-'a'+1)  ;
                    cnt[(str[j]-'a'+1)]++;
                }
            }
        }
//        print();
        
        bool ok = true;
        
        for(int i = 29  ; i >= 1 ; i-- ) {
            
            ok &= solve(i)  ;
            
        }
        int ans = 0;
        
        for(int i = 1 ; i <= 26 ; i++ ) {
            
            if( lup[i] == pii(-1,-1)) continue;
            
            else ans++;
        }
        
        
        for(int i =0 ; i < n ; i++ ) {
            for(int j = 0 ; j < m ; j++ ) {
                if(ara[i][j] >=1 && ara[i][j] <= 26) ok = false;
            }
        }
        if( !ok  ) {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        cout<<ans<<'\n';
        
        for(int i = 1; i <= 26 ; i++ ) {
            if( lup[i] == pii(-1,-1)) continue;
            
            cout<<lup[i].uu+1<<" "<<lup[i].vv+1<<" "<<rdn[i].uu+1<<" "<<rdn[i].vv+1<<'\n';
        }
    }
    return 0;
}