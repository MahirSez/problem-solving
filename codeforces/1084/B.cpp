#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e15
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
ll s , ara[MAX];
int main()
{
    fastRead;
    cin>>n>>s;
    ll sum = 0;
    ll mn = INF;
    for(int i =0; i <n ; i++ ){
        cin>>ara[i];
        sum += ara[i];
        mn = min(mn , ara[i]);
    }
    if( sum < s) {
        cout<<-1<<endl;
        return 0;
    }
    sum =0;
    for(int i =0 ; i < n ; i++) {
        sum += ara[i] - mn;
    }
    if( sum >= s) {
        cout<<mn<<endl;
        return 0;
    }

    s -= sum;
    ll tmp = (s-1) /n + 1;
    ll tt = tmp * n;
    cout<<mn - tmp<<endl;
    return 0;

}
