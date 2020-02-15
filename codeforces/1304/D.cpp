#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

string str;

/*
1
3 <<
*/



int n ;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t-- ) {
        
        
        vector<pii>rec;
        cin>>n>>str;
        
        for(int i =0 ; i < n-1 ; i++ ) {
            
            
//            cout<<i<<'\n';
            if(str[i] == '>') continue;
            
            
            int frm = i , to;
            for(int j = i ; j < n-1 ; j++ ) {
                
                if(str[j] == '<') to = j , i = j+1;
                else break;
            }
//            cout<<frm<<" "<<to<<'\n';
            rec.push_back({frm , to});
        }
        
        int now = 0;
        
        vector<int>vec1(n) ,vec2(n);
        
        for(int i =0 ; i < n-1 ; i++ ) {
            
            if(str[i] == '<') vec1[i] = ++now;
        }
        now = n;
        for(int i = 0 ; i  < n ; i++ ) {
            
            if(vec1[i] == 0) vec1[i] = now--;
        }
        
        reverse(rec.begin() , rec.end()) ;
        
        
        now = 0;
        for(auto x : rec) {
            
            int frm = x.uu;
            int to = x.vv;
            
            for(int i =frm  ; i <=to ; i++ ) vec2[i] = ++now;
        }
        now = n;
        
        for(int i =0 ; i < n ; i++ ) {
            
            if(vec2[i] == 0 ) vec2[i] = now--;
        }
        
        for(auto x : vec2) cout<<x<<" ";
        cout<<'\n';
        for(auto x : vec1) cout<<x<<" ";
        cout<<'\n';
    }
    
    return 0;
}