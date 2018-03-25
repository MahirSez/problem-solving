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
ll n , u ;
vector<ll>v;
double mx = 0;
int main()
{
    cin>>n>>u;
    for(int  i =0 ; i < n;i++ ) {
        ll tmp ;
        cin>>tmp;
        v.push_back(tmp);
    }

    for(int i = 0 ; i< n - 2 ;i++ ) {

        int id = upper_bound(v.begin()+ i + 2 , v.end() , ( v[i] +u ) ) - v.begin() -1;
//        cout<<i<<" "<<id<<endl;

        double lob = v[id] - v[i+1];
        double hor = v[id] - v[i];
        double tmp = lob / hor;
        mx = max( mx , tmp);
//            cout<<i<<" "<<v[i]<<" "<<v[i+1]<<" "<<v[id]<<" "<<tmp<<" "<<mx<<endl;
    }
    if( mx == 0) cout<<-1<<endl;
    else cout<<setprecision(13)<<fixed<<mx<<endl;
    return 0;
}
