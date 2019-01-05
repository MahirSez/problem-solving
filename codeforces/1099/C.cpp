#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string str;
int n;
int ara[3000] , candy , snow;

void solve() {
    int genSize = str.size() - candy - snow;

    reverse(str.begin() , str.end()) ;
    string ans = "";

    int extra = genSize - n;
//    cout<<extra<<" "<<n<<" "<<genSize<<endl;

    for(int i =0 ; i < str.size() ; i++ ) {

        if( (str[i] == '?' || str[i]=='*') && extra >0) {
            i++;
            extra--;
        }
        else if( str[i] != '?' && str[i] != '*') ans += str[i];
    }
    reverse(ans.begin() , ans.end()) ;
    cout<<ans<<endl;

}
int main()
{
    cin>>str>>n;
    for(int i = 0 ; i < str.size() ; i++ ) {

        if( str[i] =='?') {
            ara[i] = 1;
            candy++;
        }
        else if( str[i] =='*') {
            ara[i] = 2;
            snow++;
        }
    }
    int sz = str.size();

    if( snow ==0 && sz - candy <n) {
        //string too small
        cout<<"Impossible"<<endl;
        return 0;
    }

    if(sz - 2*candy - 2*snow > n ) {
        //string too big
        cout<<"Impossible"<<endl;
        return 0;
    }

    if( snow == 0 && candy ==0 && str.size() == n) {
        cout<<str<<endl;
        return 0;
    }
    int genSize = sz - candy - snow;
    bool taken = false;

    int extraDrkar = n - genSize;


    if( extraDrkar < 0) {

        solve();
        return 0;
    }

    for(int i =0 ; i < sz ; i++ ) {

        if( str[i] == '?') continue;
        else if( str[i] == '*' && !taken) {
            taken = true;
            while( extraDrkar-- ) cout<<str[i-1];
        }
        else if( str[i] == '*') continue;
        else cout<<str[i];
    }

    cout<<endl;
    return 0;
}
