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
int n ; 
string s , t , p;
int rec[50];

int main()
{
    fastRead;
    cin>>n;
    while( n-- ) {
        
        cin>>s>>t>>p;
        memset(rec , 0 , sizeof rec);
        
        for(auto x : p) {
            rec[x - 'a']++;
        }
        int ss = s.size();
        int tt = t.size();
        
        
        int id1 = 0 , id2 = 0;
        bool ok = true;
        
        while( id1 < ss && id2 < tt ) {
            
            if( s[id1] == t[id2]) {
                id1++;
                id2++;
                continue;
            }
            
            int tmp1 = (t[id2]-'a');
            
            if( rec[tmp1] <= 0 ) {
                ok = false;
                break;
            }
            else {
                rec[tmp1]--;
                id2++;
            }
        }
        
//        cout<<id1<<" "<<id2<<endl;
        
        while( id2 < tt) {
            int tmp1 = (t[id2]-'a');
            if( rec[tmp1] <= 0 ) {
                ok = false;
                break;
            }
            else {
                rec[tmp1]--;
                id2++;
            }
        }
//        cout<<id1<<" "<<id2<<endl;
        
        if( id1 < ss) ok = false;
        
        if( !ok ) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
        }
    }
    return 0;
}

/*
1
a
aaaa
aabbcc
*/