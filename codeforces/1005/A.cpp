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
int ara[MAX] , n;
vector<int>ans;
int main()
{
    fastRead;
    cin>>n;
    int now =1 ;
    for(int i =0 ; i < n ; i++ ) {
        int tmp;
        cin>>tmp;
        if( tmp != now ) {
            ans.push_back(now-1);
            now = tmp;
        }
        now++;
    }
    ans.push_back(now-1);
    cout<<ans.size()<<endl;
    for(int i= 0 ; i< ans.size() ; i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
