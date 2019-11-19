#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int n , m , chic  , rice;

vector<char>vec;
int ara[200][200] ,now  , cnt , tgt;
char ans[200][200];


void pre() {
    
    for(char ch = 'a' ; ch<='z' ; ch++) vec.push_back(ch);
    for(char ch = 'A' ; ch<='Z' ; ch++) vec.push_back(ch);
    for(char ch = '0' ; ch<='9' ; ch++) vec.push_back(ch);
//    for(auto x : vec) cout<<x;
//    cout<<'\n';
    
}

void print() {
    
    for(int i =0 ; i < n ; i++ ) {
        for(int j =0 ; j < m ;j++ ) {
            cout<<ans[i][j];
        }
        cout<<'\n';
    }
}


void update(int i , int j) {
    
    
    if(ara[i][j] == 0 ) {
        ans[i][j] = vec[now];
        return;
    }
    
    if(cnt < tgt)  {
        
        cnt++;
        ans[i][j] = vec[now];
        return;
    }
    
        
    rice -= tgt;
    chic--;
    
    now++;
    cnt = 1;
    tgt = (rice-1)/chic + 1;  

    ans[i][j] = vec[now];
}


void solve() {

    
    tgt = (rice-1)/chic + 1;
    cnt= 0;
    now = 0;
    
//    cout<<tgt<<'\n';
//    return;
    
    for(int i =0 ;i < n ; i++ ) {
        
        
        for(int j = 0 ; j < m && i%2 == 0; j++ ) {
            update(i,j);
            
        }
        
        for(int j = m -1 ; j>= 0 && i%2== 1; j-- ) {
            
            update(i,j);
        }
    }
    
}


int main()
{
    fastRead;
    
    pre();
    int t;
    cin>>t;
    while(t--) {
        
        cin>>n>>m>>chic;
        rice = 0;
        memset(ara , 0 , sizeof ara);
        for(int i =0 ;i < n ; i++ ) {
            for(int j =0 ;j < m ;j++ ) ans[i][j] = '.';
        }
        
        for(int i = 0 ; i < n ; i++ ) {
            string str;
            cin>>str;
            for(int j =0 ; j <m ; j++ ) {
                if(str[j] == 'R') ara[i][j] = 1 , rice++;
            }
        }
        
        
        solve();
        print();
    }
    
    return 0;
    
}

/*
1
3 5 3
..R..
...R.
....R
*/