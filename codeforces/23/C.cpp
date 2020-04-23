#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define ppl         pair<pll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n ;
        cin>>n;
        vector<ll>a(2*n) , b(2*n) ;
        vector<ppl>vec ;
        
        ll tot1 = 0 , tot2 = 0;
        
        ll taken1= 0 , taken2 = 0;
        
        for(int i= 0 ; i <2* n-1 ; i++) {
            
            cin>>a[i]>>b[i];
            tot1 += a[i];
            tot2 += b[i];
            vec.push_back({ {a[i] , b[i]} , i});
        }
        sort(vec.begin() , vec.end());
        
        for(int i = 0 ; i < 2*n-1 ; i+=2 ) {
            taken1 += vec[i].uu.uu;
            taken2 += vec[i].uu.vv;
        }
        
        cout<<"YES\n";
        
        if(taken1*2 >= tot1 && taken2 *2 >= tot2) {
            
            for(int i = 0 ; i < 2*n-1 ; i+=2 ) {
                cout<<vec[i].vv+1<<" ";
            }
            cout<<'\n';
        }
        else {
            
            for(int i =1 ; i < 2*n-1 ; i+=2 ) {
                cout<<vec[i].vv+1<<" ";
            }
            cout<<vec[2*n-2].vv+1<<'\n';
        }
        
        
    }
    return 0;
}