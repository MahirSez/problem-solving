#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll ,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	5000006
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


int n , k;
string str , sub;
map<pll , int>mp;
pll h[MAX] , p_pow[MAX];


pll Hash(string  s) {


    pll val = {0,0};

    for(int i =0 ; i < s.size() ; i++ ){
        val = (val + p_pow[i] *(int)s[i])%mod;
    }
    return (val *p_pow[MAX-2])%mod;
}


pll getHash(int id , int len) {

    pll tmp = (h[id+len-1] + mod - h[id-1])%mod;
    return (tmp * p_pow[MAX-1-id])%mod;
}

int main()
{
    fastRead;
    cin>>n>>k>>str;

    p_pow[0] = {1,1};
    str += str;

    for(int i =1 ; i < MAX ; i++  ) {

        p_pow[i] = (p_pow[i-1] *p)%mod;
    }

    for(int i =0 ; i < str.size() ; i++ ) {

        h[i+1] = (h[i] + p_pow[i]* (int)str[i] )%mod;
    }
    int g;
    cin>>g;
    for(int i= 1 ; i <= g ; i++ ) {

        cin>>sub;
        mp[Hash(sub)] = i;
    }


    for(int i = 1 ; i <= k ;i++ ) {

        vector<int>ans;
        set<int>rec;

        for(int j = i , cnt = 0; cnt<n ; j+= k ,cnt++) {

            pll tmp = getHash(j , k);

            if( mp.find(tmp) == mp.end()) break;

            rec.insert(mp[tmp]);
            ans.push_back(mp[tmp]);

        }

        if( rec.size() == n ) {

            cout<<"YES"<<endl;
//            cout<<ans.size()<<endl;
            for(int i = 0 ; i < ans.size() ;i++ ) cout<<ans[i]<<" ";
            cout<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;

}
