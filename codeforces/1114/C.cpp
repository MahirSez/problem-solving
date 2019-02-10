#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e18
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll n , b;
vector<ll>prm;
int isPrime[MAX];
vector<ll>str;
map<ll , ll>mp;

void seive() {

    for(int i =2 ; i* i < MAX ; i++) {
        if( isPrime[i]) continue;
        for(int j = i *i ; j < MAX ; j+=i) {
            isPrime[j] = 1;
        }
    }

    for(int i =2  ; i < MAX ; i++) {
        if(isPrime[i] ==0 ) {
            prm.push_back(i);
            // if( i < 100 ) cout<<i<<" ";
        }
        
    }
    // cout<<endl;
}
int main()
{
    seive();
    cin>>n>>b;
     //n = (1LL <<60);
    // b = 2;
    // cout<<prm.size()<<endl;

    for(int i =0 ; i < (int)prm.size() ; i++ ) {
        
        int prime = prm[i];
        if( b%prime) continue;
        int cnt = 0;
        while(b%prime==0) {
            b/=prime;
            cnt++;
        }
        mp[prime] = cnt;
    }
    if(b != 1) mp[b]++;
    // cout<<mp.size()<<endl;

    long long  int ans = 9223372036854775807;
    //cout<<ans<<endl;
    for( auto x : mp) {


        ll prime = x.first;
        ll cnt = x.second;
        

        ll sum = 0;

        ll tmp = n;
        
        
        while( tmp / prime  > 0) {
            sum += (tmp/prime);
            //cout<<tmp<<" "<<prime<<endl;
            tmp /= prime;
        }
        ans = min( ans , sum / cnt);
        
    }
    cout<<ans<<endl;
    return 0;
}