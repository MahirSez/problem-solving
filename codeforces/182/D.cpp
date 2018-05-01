#include <bits/stdc++.h>
#define ll          long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
string big , sml;
int bs , ss , cmn;
vector<int>v;


bool ok(int val) {

    string s = "";
    for(int i =0 ; i < val ;i++ ) {
        s+=sml[i];
    }

    for(int i = 0 , j = 0 ; i < sml.size() ; i++ , j++) {

        if( j == val) j= 0 ;

        if(s[j] != sml[i]) return false;
    }
    for(int i =0 , j = 0 ;  i < big.size() ; i++ , j++) {

        if( j == val) j = 0;

        if( s[j] != big[i]) return false;
    }
    return true;
}


int solve() {

    int tot = 0;

    for(int i = 0; i < v.size() ; i++ ) {

        int val = v[i];
        if( ok(val) ) tot++;
    }
    return tot;
}


int main()
{
    cin>>big>>sml;
    if( big < sml) swap(big, sml);
    bs = big.size() ;
    ss = sml.size();
    cmn = __gcd(bs , ss);

    for(int i =1 ; i<= cmn ; i++ ) {
        if( cmn % i == 0 )  v.push_back(i);
    }

    cout<<solve()<<endl;

    return 0;
}
