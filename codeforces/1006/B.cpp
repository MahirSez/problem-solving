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
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , k , ara[MAX];
vector<pii>v;
vector<int>str, ans;
int main()
{
    fastRead;
    cin>>n>>k;
    for(int i = 0 ; i < n ; i++ ) {
        cin>>ara[i];
        v.push_back({ara[i],i});
    }
    sort(v.rbegin() , v.rend());
    int tot = 0;
    for(int i= 0 ; i < k ; i++ ) {
        str.push_back(v[i].vv+1);
        tot += v[i].uu;
    }
    sort( str.begin() , str.end() ) ;
    cout<<tot<<endl;
    int now = 0  ;
    for(int i =0 ; i < k-1 ; i++ ) {
        printf("%d ", str[i]- now);
        now = str[i];
    }
    printf("%d\n",n-now);
    return 0;
}
