#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	998244353
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
vector<ll> rec , v;
map<ll , ll>mp;
map<ll , ll > taken;

bool check4(ll tmp) {
    ll rt1 = sqrt(tmp);
    if( rt1 * rt1 != tmp) return false;
    ll rt2 = sqrt(rt1);
    if(rt2 * rt2 == rt1) {
        if( mp[rt2] ==0 ) rec.push_back(rt2);
        mp[rt2] += (4*taken[tmp]);
        return true;
    }
    return false;
}

bool check2(ll tmp) {
    ll rt1 = sqrt(tmp);
    if( rt1 * rt1 != tmp) return false;
    if( mp[rt1] == 0 ) rec.push_back(rt1);
    mp[rt1] += 2*taken[tmp];
    return true;
}

bool check3(ll tmp) {
    ll rt1 = cbrt(tmp);
    if( rt1 * rt1 * rt1 != tmp ) {
        rt1++;
        if( rt1 * rt1 * rt1 != tmp) return false;
    }
    if( mp[rt1] == 0 ) rec.push_back(rt1);
    mp[rt1] += 3 * taken[tmp];
    return true;
}



//1003012019036027027
int main()
{
    cin>>n;
    ll ans = 1LL;

    for(int i =0 ; i < n ; i++ ) {
        ll tmp;
        cin>>tmp;
        if(taken[tmp] == 0) v.push_back(tmp);
        taken[tmp]++;
    }

//    for(int i =0 ; i < n ;i++ ) {
//        ll cnt , tmp = 1 ;
//        cin>>cnt;
//        while( cnt -- ) {
//            ll num;
//            cin>>num;
//            tmp *=num;
//        }
//        if(taken[tmp] == 0) v.push_back(tmp);
//        taken[tmp]++;
//    }

    for(int i =0 ; i < v.size() ; i++ ) {
        ll tgt = v[i];
//        cout<<tgt<<endl;

        if( check4(tgt) || check2(tgt) || check3(tgt) ) {
            continue;
        }
        bool ok = 0;
        for(int j = 0 ; j < v.size() ; j++) {
            if( i==j) continue;

            ll gcd = __gcd(tgt , v[j]);
            if( gcd ==1 ) continue;

            if( mp[gcd] ==0 ) rec.push_back(gcd);
            mp[gcd] += taken[tgt];
            if( mp[tgt/gcd] ==0 ) rec.push_back(tgt/gcd);
            mp[tgt/gcd] += taken[tgt];
            ok = 1;
            break;
        }

        if( !ok ) {
            ans = (ans * (taken[tgt] + 1 ) % MOD ) % MOD;
            ans = (ans * (taken[tgt] + 1 ) % MOD ) % MOD;
        }

    }

    for(int i =0 ; i < rec.size() ; i++ ) {
        ll tmp = rec[i];
//        cout<<rec[i]<<" "<<mp[tmp]<<endl;
        ans = (ans * (mp[tmp] + 1)%MOD) % MOD;
    }
    cout<<ans<<endl;
    return 0;
}
