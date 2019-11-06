#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e5 + 6;

string s1  , s2;    
int n;

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--)  {
            
        cin>>n>>s1>>s2;
        
        vector<pii>vec;
        
        
        for(int i =0 ; i < n ; i++ ) {
            
            
            if(s1[i] == s2[i]) continue;
            
            
            bool ok = false;
            
            for(int j = i + 1; j < n ; j++ ) {
                if(s1[j] == s1[i]) {
                        
                    swap(s2[i] , s1[j]);
                    vec.push_back({j , i});
                    ok = true;
                    break;
                }
            }
            
            if(ok) continue;
            
            for(int j = i+1 ; j < n ; j++ )  {
                
                if(s2[j] == s1[i]) {
                    
                    swap(s2[j] , s1[i+1]);
                    
//                    cout<<i<<" "<<j<<'\n';
                    vec.push_back({i+1 , j});
                    
                    swap(s1[i+1] , s2[i]);
                    
                    vec.push_back({i+1 , i});
                    ok = true;
                    break;
                }
            }
            
            if(!ok)  break;
        }
        
        if(s1 != s2) {
            cout<<"No\n";
            continue;
        }
        
        cout<<"Yes\n";
        cout<<vec.size()<<'\n';
        for(auto x : vec) cout<<x.uu+1<<" "<<x.vv+1<<'\n';
    }
    return 0;
    
}

/*
1
3
abc
bca
*/