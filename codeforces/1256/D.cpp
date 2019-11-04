#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e3 + 3;
int q;
int main()
{
    fastRead;
    cin>>q;
    while(q--) {
        
        ll n , k;
        cin>>n>>k;
        string str ;
        cin>>str;
        
        int one = 0;
        
        for(int i =0 ; i < n && k>0 ;i++ ) {
            
            if(str[i] == '1') {
                one++;
                continue;
            }
            
            ll mn = min(one*1LL ,k);
            k -=mn;
            
            
            swap(str[i-mn] , str[i]);
        }
        
        cout<<str<<'\n';
    }
    return 0;
}