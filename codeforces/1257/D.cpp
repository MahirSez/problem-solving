#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 2e5 + 5;
int ara[MAX] , mx[MAX] , power[MAX] ;


int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--)     {
    
        int n ;
        cin>>n;
        for(int i =1 ; i <=n+2 ; i++ ) power[i] = 0 , mx[i] = 0;
        
        for(int i =1 ; i <=n ; i++ ) cin>>ara[i];
        
        int m;
        cin>>m;
        while(m-- ) {
            
            int p,s;
            cin>>p>>s;
            power[s] = max(power[s] , p);
        }
        
        for(int i = n ; i>= 1 ; i--) {
            mx[i] = max(mx[i+1] , power[i]);
//            cout<<i<<" "<<mx[i]<<" "<<mx[i-1]<<" "<<power[i]<<'\n';
        }
        
//        for(int i = 1 ; i <=n ; i++ ) cout<<i<<" "<<mx[i]<<'\n';
        
        int ans = 0;
        int now = 1 ;
        while(now <= n ) {
            
            int cnt= 1; 
            if(ara[now] > mx[1] ) {
                ans= -1;
                break;
            }
            
            int tmpmx = ara[now];
            
            while(now<=n && tmpmx<= mx[cnt] ) {
                now++;
                cnt++;
                
                tmpmx = max(tmpmx , ara[now]);
            }
                
            ans++;
            
//            cout<<" "<<now<<'\n';
        }
        
        cout<<ans<<'\n';
    }
    return 0;
}

/*
3
6
2 3 11 14 1 8
2
3 2
100 1
5
3 5 100 2 3
2
30 5
90 1
4
100 100 100 100
3
100 1
101 1
101 4

*/