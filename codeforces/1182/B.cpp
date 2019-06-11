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
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
int ara[600][600];

int n  , m , cnt;
bool ok ;

void  check(int x , int y) {

    int tmp = 1;
    int cnt1 = 0;
    
    for(int i =1 ; i < 600 ; i++ ) {
        if( x + i < n && ara[x+i][y])cnt1++;
        else break;
    }
    if( cnt1 ==0 ) return;
    tmp += cnt1;
    cnt1 = 0;
    
    for(int i =1 ; i < 600 ; i++ ) {
        if( x - i >=0 && ara[x-i][y])cnt1++;
        else break;
    }
    if( cnt1 ==0 ) return;
    tmp += cnt1;
    cnt1 = 0;
    
    for(int i =1 ; i < 600 ; i++ ) {
        if( y + i  < m && ara[x][y+i])cnt1++;
        else break;
    }
    if( cnt1 ==0 ) return;
    tmp += cnt1;
    cnt1 = 0;
    
    for(int i =1 ; i < 600 ; i++ ) {
        if( y - i >=0 && ara[x][y-i])cnt1++;
        else break;
    }
    
    if( cnt1 ==0 ) return;
    tmp += cnt1;
    cnt1 = 0;
    
    
    if(tmp == cnt) ok = true;
}


int main()
{
    fastRead;
    cin>>n>>m;
    ok = false;
    for(int i =0 ; i < n ; i++ ) {
        string str;
        cin>>str;
        for(int j =0 ; j < m ;j++ ) {
            if( str[j] =='*') ara[i][j] = 1 , cnt++;
        }
    }
    
    for(int i =0 ; i < n ; i++ ) {
        for(int j = 0 ; j < m ; j++ ) {
            
            if(ara[i][j])  {
                check(i,j);
            }
        }
    }
    if( ok ) {
        cout<<"YES\n";
    }
    else cout<<"NO\n";
    return 0;
}