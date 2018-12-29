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
ostream& operator<<(ostream & os, pll h)
{
	return os << "( " << h.uu << ", " << h.vv << " )" << endl;

}
pll operator+ (pll a, ll x)     {return {a.uu + x, a.vv + x} ;}
pll operator- (pll a, ll x)     {return {a.uu - x, a.vv - x} ;}
pll operator* (pll a, ll x)     {return {a.uu * x, a.vv * x} ;}
pll operator+(pll x, pll y) { return {x.uu + y.uu,x.vv + y.vv} ;}
pll operator-(pll x,pll y) { return {x.uu - y.uu, x.vv - y.vv} ;}
pll operator*(pll x,pll y) { return {x.uu * y.uu , x.vv * y.vv} ;}
pll operator%(pll x,pll y) { return {x.uu % y.uu, x.vv % y.vv} ;}

const pll p = {15485867,32452843};

const pll  mod = {1000000021, 1e9 + 9 };

string str[3] ;
pll p_pow[MAX] , h1[3][MAX] ;


pll hashVal1(int i , int id , int len) {

    pll tmp = (h1[i][id+len-1] +mod - h1[i][id-1])%mod;
    tmp = (tmp* p_pow[MAX-1-id])%mod;
    return tmp;
}


int getCom(int id1 , int id2) {

    int n1 = str[id1].size();
    int n2 = str[id2].size();

    for(int i = 1 ; i<= n1 ; i++ ) {

        if(hashVal1(id1 , i , n1-i+1)  == hashVal1(id2 , 1 , n1-i+1) ) {
            return n1-i+1;
        }
    }
    return 0;
}


bool sub(int id1 , int id2) {

    int bSize = str[id1].size();
    int sSize = str[id2].size();

    for(int i = 1 ; i + sSize -1 <= bSize ; i++) {

        if( hashVal1(id1 , i , sSize) == hashVal1(id2 , 1, sSize))
            return true;
    }
    return false;
}

int solve(int id1 , int id2 , int id3) {

    int n1 = str[id1].size();
    int n2 = str[id2].size();
    int n3 = str[id3].size();

    if( sub(id1, id2) ) {

        if( sub(id1 , id3) ) return n1;
        if( sub(id3 , id1) ) return n3;

        int common = getCom(id1 , id3);

        return n1 + n3 - common;
    }
    if( sub(id2 , id1)) {

        if( sub(id2 , id3) ) return n2;
        if( sub(id3 , id2) ) return n3;

        int common = getCom(id2 , id3);

        return n2 + n3 - common;
    }

    if( sub(id2, id3)) {

        if( sub(id2 , id1) ) return n2;
        if( sub(id1 , id2) ) return n1;

        int common = getCom(id1 , id2);

        return n2 + n1 - common;
    }

    if( sub(id3, id2)) {

        if( sub(id3 , id1) ) return n3;
        if( sub(id1 , id3) ) return n1;

        int common = getCom(id1 , id3);

        return n3 + n1 - common;
    }

    int common1 = getCom(id1 , id2);
    int common2 = getCom(id2 , id3);
    int ans = n1 + n2 + n3 - common1 - common2;
    return ans;
}


int main()
{

    for(int i =0 ; i < 3 ; i++ ) {
        cin>>str[i];
    }

    p_pow[0] = {1,1};

    for(int i =1 ; i <MAX; i++) {
        p_pow[i] = (p_pow[i-1]*p)%mod;
    }

    for(int i =0 ; i <3; i++ ){

        for(int j = 0 ;j < str[i].size() ; j++) {

            h1[i][j+1] = (h1[i][j] +  p_pow[j]*(int)str[i][j] )%mod;
        }
    }

    int ans  = INF;

    for(int i =0 ; i < 3 ; i++ ) {
        for(int j =0 ; j < 3;  j++ ) {
            for(int k = 0 ; k < 3 ; k++ ) {
                if( i!=j && j!=k && k!=i ) {
                    ans = min(ans , solve(i , j , k));
                }
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}



