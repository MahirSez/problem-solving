#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , m , k;
map<int,int>mp;
int main()
{
    fastRead;
    
    cin>>n>>m>>k;
    vector<int>v1(n);
    vector<int>cpy(n);
    for(int i= 0 ;i < n ; i++ ) {
        cin>>v1[i];
    }
    cpy = v1;
    sort(cpy.rbegin() , cpy.rend());
    ll ans = 0;
    for(int i =0 ; i < m*k ; i++) {
        mp[cpy[i]]++;
        ans += cpy[i];
    }
    int cnt = 0;
    int koybar = 0;
    cout<<ans<<endl;
    for(int i =0 ; i < n ; i++) {
        
        int x = v1[i];

        if( mp[x] ==0) continue;
        else {
            cnt++;
            mp[x]--;
        }
        if( cnt == m) {
            cout<<i+1<<" ";
            
            cnt = 0;
            koybar++;
            if( koybar == k-1) break;
        }
    }
    cout<<endl;
    return 0;
}

