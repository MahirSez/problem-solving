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
int taken[200] , arap[200];
vector<int>v;
int n , k;
int main()
{
    cin>>n>>k;
    for(int i =0 ; i < n ; i++ ) {
        int tmp;
        cin>>tmp;
        if( taken[tmp] == 0 ) {
            v.push_back(i);
            taken[tmp] = 1;
        }
    }
    int sz = v.size();
    if( sz < k ) {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int  i=0 ; i < k ; i++ ) {
        cout<<v[i] + 1<<" ";
    }
    cout<<endl;
    return 0;
}
