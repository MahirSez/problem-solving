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
int n  ;
string s1 , s2;
int main()
{
    fastRead;
    cin>>n;
    while( n-- ) {
        cin>>s1>>s2;
        
        vector<pii>vec1 , vec2;
        
        int last = -1 , cnt = 0;
        for(int i =0 ; i  < s1.size() ; i++ ) {
            
            int id = s1[i] - 'a';
            if( id != last ) {
                if( last != -1 ) vec1.push_back({last , cnt});
                cnt = 1;
                last = id;
            }
            else cnt++;
        }
        vec1.push_back({last , cnt});
        
        last = -1 , cnt = 0;
        for(int i =0 ; i  < s2.size() ; i++ ) {
            
            int id = s2[i] - 'a';
            if( id != last ) {
                if( last != -1 ) vec2.push_back({last , cnt});
                cnt = 1;
                last = id;
            }
            else cnt++;
        }
        vec2.push_back({last , cnt});
        
        if( vec1.size() != vec2.size()) {
            cout<<"NO\n";
            continue;
        }
        
        bool ok = true;
        for(int i =0 ; i < vec1.size() ; i++ ) {
            
            int id1 = vec1[i].uu;
            int cnt1 = vec1[i].vv;
            
            int id2 = vec2[i].uu;
            int cnt2 = vec2[i].vv;
            
            if( id1 != id2 || cnt2 < cnt1 ) ok = false;
        }
        if( ok) cout<<"YES\n";
        else cout<<"NO\n";
        
    }
    return 0;
}