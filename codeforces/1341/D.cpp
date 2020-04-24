#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 3000 + 6;

string s[] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };

string str[MAX];
int n , k , ara[MAX] , cnt[MAX] , ans[MAX];

int mp[(1<<10)]  ,dp[MAX][MAX];

vector<int>rec;


int convert(string tmp)  {
    
    int vall = 0;
    for(auto x : tmp) {
        vall *= 2;
        vall += int(x-'0');
    }
    return vall;
}

void process() {
    
    memset(mp , -1 , sizeof mp);
    
    for(int i =0 ; i < 10 ; i++ ) {
        
        int tmp= convert(s[i]);
        mp[tmp] = i;
        rec.push_back(tmp);
    }
    reverse(rec.begin()  , rec.end());
}


int main()
{
    fastRead;
    process();
    
    cin>>n>>k;
    for(int i = 1 ; i <=n  ; i++ ) {
        cin>>str[i];
        ara[i] = convert(str[i]);
    }
    dp[n+1][k] = 1;
    
    for(int i = n ; i >=1 ; i-- ) {
        
        for(auto x : rec ) {
            
            if( (x & ara[i]) != ara[i] ) continue;
            
            int lagbe = __builtin_popcount(x ^ ara[i]);
            
            for(int j = 0 ; j <= k ; j++ ) {
                
                dp[i][j] |= dp[i+1][j+lagbe];
            }
            
        }
    }
    
    
    if(dp[1][0]==0) {
        cout<<-1<<'\n';
        return 0;
    }
    
    int kk = 0;
    for(int i = 1; i <=n ; i++ ) {
        
        for(auto x : rec ){
            
            if( (x & ara[i]) != ara[i] ) continue;
            
            int lagbe = __builtin_popcount(x ^ ara[i]);
            
            if(dp[i+1][kk+lagbe]) {
                kk += lagbe;
                cout<<mp[x];
                break;
            }
        }
    }
    cout<<'\n';
    return 0;
    
}