#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 500;
int t , n , ara[MAX] , rec[10004];
int main()
{
    fastRead;
    
    cin>>t;
    while(t--) {
        cin>>n;
        n*=4;
        for(int i =0 ; i < n ; i++ )cin>>ara[i] ;
        
        sort(ara ,ara + n);
        
        int tgt = ara[0] *ara[n-1];
        
        
        
        
        bool ok =true;
        
//        cout<<tgt<<endl;
        for(int i =0 ; i < n ; i++ ) {
                
            bool ok1 = false , ok2 = false, ok3 = false;
            
            if(ara[i] ==0 ) continue;
            
            if(tgt % ara[i] ) {
                ok = false;
                break;
            }
            
//            cout<<ara[i]<<" "<<tgt/ara[i]<<endl;
            
            for(int j = i+1 ; j < n ; j++ ) {
                
                if(ara[j] == ara[i] ) {
                    ara[j] = 0;
                    ok1= true;
                    break;
                }
            }
            for(int j = i+1 ; j < n ; j++ ) {
                
                if(ara[j] == tgt/ara[i]) {
//                        cout<<" "<<ara[i]<<" "<<tgt/ara[i]<<" "<<ara[j]<<endl;
                    ara[j] = 0;
                    ok2 = true;
                    break;
                }
            }
            for(int j = i+1 ; j < n ; j++ ) {
                
                if(ara[j] == tgt/ara[i]) {
                    ara[j] = 0;
                    ok3 = true;
                    break;
                }
            }            
            
            if( ok1 == false || ok2 == false || ok3 == false) {
                ok = false;
                break;
            }
            ara[i] = 0;
            
            
//            for(int i =0 ; i < n ; i++ ) {
//                cout<<ara[i]<<" ";
//                
//            }
//            cout<<endl;
            
        }
        if( ok ) cout<<"YES\n";
        else cout<<"NO\n";
        
    
    }
    return 0;
    
    
    
}