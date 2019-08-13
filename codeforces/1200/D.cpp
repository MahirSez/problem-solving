#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 2e3 + 3;
int n , k;
int ara[MAX][MAX] , f[MAX] , s[MAX];
int ans1[MAX][MAX] , ans2[MAX][MAX];



void solve1() {
    
    memset(f , -1 , sizeof f);
    memset(s , -1 , sizeof s);
    int rt = 0;
    
    for(int i =0 ; i < n ; i++ ) {
        
        for(int j =0 ; j < n ; j++ ) {
            
            if( ara[i][j] )  s[i] = j;
        }
        for(int j = n-1 ; j >=0 ; j-- ) {
            if( ara[i][j] ) f[i] = j;
        }
        if( f[i] == -1) rt++;
    }
    
    for(int col =0 ; col +k-1< n ; col++ ) {
        
        
        int frmCol = col;
        int toCol = col+k-1;
        
        
        int tmp = rt;
        for(int i =0 ; i < k ; i++  ) {
            
            if(f[i] != -1 && f[i]>=frmCol && s[i] <= toCol ) tmp++;
        }

        ans1[0][col] = tmp ;    
        
        for(int i =1 ; i + k-1< n ; i++ ) {
                
            int lastRo = i-1;
            
            int newRo = i + k-1;
            
            if(f[lastRo] != -1 && f[lastRo] >= frmCol && s[lastRo] <= toCol) tmp--;
            
            if(f[newRo] != -1 && f[newRo] >= frmCol && s[newRo] <= toCol ) tmp++;
            
            ans1[i][col] = tmp ;
        }
    }
}

void solve2() {

    memset(f , -1 , sizeof f);
    memset(s , -1 , sizeof s);
    
    int rt = 0;
    
    for(int j =0 ; j < n ; j++ ) {
        
        for(int i =0 ; i < n ; i++ ) {
            
            if(ara[i][j]) s[j] = i;
        }
        for(int i = n-1;  i >= 0 ; i-- ) {
            
            if(ara[i][j]) f[j] = i;
        }
        if( f[j] == -1 ) rt++;
    }
    
//    cout<<" "<<rt<<endl;
    
    for(int ro =0 ; ro +k-1< n ; ro++ ) {
        
        
        int frmRo = ro;
        int toRo = ro+k-1;
        
        
        int tmp = rt;
        for(int i =0 ; i < k ; i++  ) {
            
            
            if(f[i] != -1 && f[i]>=frmRo && s[i] <= toRo ) tmp++;
        }

        ans2[ro][0] = tmp ;    
        
        for(int i =1 ; i + k-1< n ; i++ ) {
                
            int lastCol = i-1;
            
            int newCol = i + k-1;
            
            if(f[lastCol] != -1 && f[lastCol] >= frmRo && s[lastCol] <= toRo) {
                    
                
                tmp--;
            }
            
            if(f[newCol] != -1 && f[newCol] >= frmRo && s[newCol] <= toRo ) tmp++;
            
            ans2[ro][i] = tmp;
        }
    }
    
}

void print1() {
    
    for(int i =0 ; i + k-1< n; i++ ) {
        for(int j =0 ; j + k -1 < n  ;j++  ) {
            cout<<ans1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void print2() {
    
    for(int i =0 ; i + k-1< n; i++ ) {
        for(int j =0 ; j + k -1 < n  ;j++  ) {
            cout<<ans2[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}



int main()
{
    fastRead;
    cin>>n>>k;
    string str;
    for(int i =0 ; i < n ; i++ ) {
        
        cin>>str;
        for(int j =0 ; j < n ; j++ ) {
            
            if( str[j] == 'B') ara[i][j] = 1;
        }
    }
    solve1();
//    print1();
    solve2();
    
//    print2();
    
    
    int ans = 0;
    
    
    for(int i =0 ; i < n ; i++ ) {
        for(int j =0 ; j < n ; j++ ) ans = max(ans , ans1[i][j] + ans2[i][j]) ;
    }
    cout<<ans<<'\n';
    
    return 0;
}