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
int n, ara[1000];
int main()
{
    cin>>n;
    for(int i =0 ; i < n/2 ;i++ ) cin>>ara[i];
    sort( ara , ara + n/2);
    int ans1 = 0 , ans2 = 0;
    for(int i = 0, cnt1= 2, cnt2 = 1; i<n/2 ; i++ , cnt1+=2 , cnt2+=2) {
        ans1 += abs( cnt1 - ara[i]);
        ans2 += abs( cnt2 - ara[i]);
    }
    cout<<min( ans1, ans2 )<<endl;
    return 0;
}
