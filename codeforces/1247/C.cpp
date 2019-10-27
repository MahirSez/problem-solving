#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;



bool ok (ll n , int cnt) {

//    if(__builtin_popcount(n) > cnt) return false;
//    int tmp = 0;
//    
//    
//    int aa = 0;
//    
//    while(n) {
//        
//        if(n&1) {
//            if(tmp > 0 ) aa += (1<<(tmp-1));
//        }
//        tmp++;
//        n/=2;
//    }
//    return ( __builtin_popcount(n) <= cnt && aa >= cnt);

    return (__builtin_popcount(n) <= cnt && cnt <= n);
}

int main()
{
    fastRead;
    ll n , p;
    cin>>n>>p;
    
    for(int i =1 ; i < 1000000 ; i++ ) {
        
        n-= p;
//        cout<<n<<'\n';
        if(n <= 0) break;
        if(ok(n , i)) {
            cout<<i<<'\n';
            return 0;
        }
    }
    
    cout<<-1<<'\n';
    return 0;
    
}