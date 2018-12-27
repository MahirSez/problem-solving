#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll     	pair<ll,ll>
#define INF     	1e18
#define EPS     	1e-8
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string str , s1 , s2;

const int p1 = 31;
const int p2 = 37;

const int mod1 = 1e9+9;
const int mod2 = 1e9+7;

ll h[2][MAX] , p1_pow[MAX] , p2_pow[MAX] , s1Hash[2] , s2Hash[2];
bool ok1 , ok2 ;

void computeHash() {
    for(int i = 0 ; i  <str.size() ; i++ ) {

        h[0][i+1] = (h[0][i] + (str[i]-'a'+1)*p1_pow[i])%mod1;
        h[1][i+1] = (h[1][i] + (str[i]-'a'+1)*p2_pow[i])%mod2;
    }
}

pll getHash(int id, int len) {

    ll tmp1 = (h[0][id+len-1] + mod1 - h[0][id-1]) %mod1;
    tmp1 = (tmp1* p1_pow[MAX-1-id])%mod1;

    ll tmp2 = (h[1][id+len-1] + mod2 - h[1][id-1])%mod2;
    tmp2 = (tmp2*p2_pow[MAX-1-id])%mod2;
//    cout<<id<<" "<<len<<"----- "<<tmp1<<" "<<tmp2<<endl;

    return {tmp1 , tmp2};
}

bool ok()
{

    int nxt = MAX;

    for(int i = 1 ;i +s1.size()-1<= str.size() ; i++ ) {

        pll tmp = getHash(i , s1.size());
        if( tmp == pll(s1Hash[0] , s1Hash[1] ) ) {
            nxt = i+s1.size();
            break;
        }
    }
    for(int i = nxt ;i +s2.size()-1<= str.size() ; i++ ) {

        pll tmp = getHash(i , s2.size());
        if( tmp == pll(s2Hash[0] , s2Hash[1]) ) {
            return true;
        }
    }
    return false;
}

int main()
{
    cin>>str>>s1>>s2;

    p1_pow[0] = p2_pow[0] = 1;
    for(int i =1 ; i <MAX; i++ ){
        p1_pow[i] = (p1_pow[i-1] * p1)%mod1;
        p2_pow[i] = (p2_pow[i-1] * p2)%mod2;
    }


    for(int i = 0 ; i < s1.size(); i++ ) {
        s1Hash[0] = (s1Hash[0] + (s1[i] - 'a' + 1)*p1_pow[i] )%mod1;
        s1Hash[1] = (s1Hash[1] + (s1[i] - 'a' + 1)*p2_pow[i] )%mod2;
    }

    for(int i =0 ; i < s2.size() ; i++ ) {
        s2Hash[0] = (s2Hash[0] + (s2[i] - 'a' + 1)*p1_pow[i] )%mod1;
        s2Hash[1] = (s2Hash[1] + (s2[i] - 'a' + 1)*p2_pow[i] )%mod2;
    }

    s1Hash[0] = (s1Hash[0] * p1_pow[MAX-2])%mod1;
    s1Hash[1] = (s1Hash[1] * p2_pow[MAX-2])%mod2;

    s2Hash[0] = (s2Hash[0] * p1_pow[MAX-2])%mod1;
    s2Hash[1] = (s2Hash[1] * p2_pow[MAX-2])%mod2;

//    cout<<s1Hash[0]<<" "<<s1Hash[1]<<endl;
//    cout<<s2Hash[0]<<" "<<s2Hash[1]<<endl;


    computeHash();
    ok1 = ok();
    reverse(str.begin() , str.end());
    computeHash();
    ok2 = ok();

    if( ok1 && ok2) cout<<"both"<<endl;
    else if( ok1 ) cout<<"forward"<<endl;
    else if( ok2) cout<<"backward"<<endl;
    else cout<<"fantasy"<<endl;
    return 0;
}
