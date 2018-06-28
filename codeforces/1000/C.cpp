#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<ll,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
map<ll , bool>mp;
vector<pii>v;
ll ans[MAX];
int main()
{
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        ll a , b;
        cin>>a>>b;
        v.push_back({a,0});
        v.push_back({b,1});
    }
    sort( v.begin() , v.end());
    ll now = v[0].uu ;
    int cnt = 0 ;
    for(int i =0 ; i < v.size() ; i++ ) {
        int it = i , shuru = cnt , shesh = 0;
        while( it < v.size() && now == v[it].uu ) {
            cnt++;
            if( v[it].vv == 0) shuru++;
            else shesh++;
            it++;
        }
        cnt = shuru - shesh;
//        cout<<now<<" "<<cnt<<" "<<shuru<<endl;
        ans[shuru]++;
        if( it >= (int)v.size() )break;
        ll majhe = v[it].uu - now - 1LL ;

        if( majhe > 0 ) {
            ans[cnt] += majhe;
        }
        now = v[it].uu;
        i = it-1;
    }
    for(int i =1 ; i <=n ; i++ ) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}
