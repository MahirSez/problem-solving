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
int n , ara[MAX];
vector<int>v;
vector<int>ans;
int main()
{
    fastRead;
    cin>>n;
    for(int  i= 1 ; i <= n ; i++ ) cin>>ara[i];
    for(int i = 0 ; i < n ; i++  ) {
        v.push_back(ara[i+1] - ara[i]);
    }

    for(int i = 1 ; i<= n ; i++ ) {

        bool ok = true;


        for(int j = 0 , k = i ; k < v.size() ; j++ , k++  ) {

            if( v[j] != v[k]) {
                ok= false;
            }
        }
        if( ok) ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(int i =0 ; i < ans.size() ; i++ ) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
