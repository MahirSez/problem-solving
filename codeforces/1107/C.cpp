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
int n , k;
vector<ll>v;
ll ara[MAX];
string str;
int main()
{
    ll ans= 0;
    fastRead;
    cin>>n>>k;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    cin>>str;
    str +='*';
    int cnt =0;

    for(int i =0 ; i < n ; i++ ) {
        cnt++;
        v.push_back(ara[i]);
        if( str[i] != str[i+1]) {
            sort(v.rbegin() , v.rend());

            for(int j =0 ; j < min((int)v.size() , k) ; j++ ) {
                ans += v[j];
            }
            v.clear();
        }
    }
    cout<<ans<<endl;
    return 0;
}
