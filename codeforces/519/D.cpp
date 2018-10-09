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
ll ara[30] ;
string str;
ll sum;
map<pair<char,ll> , ll> mp;
int main()
{
    for(int i =0 ; i < 26 ; i++ ) cin>>ara[i];
    cin>>str;
    ll cnt =0 ;
    for(int i =0 ; i < str.size() ; i++ ) {
        char ch = str[i];
        cnt += mp[{ch , sum}];
        sum += ara[str[i] - 'a'];
        mp[{ch , sum}]++;
    }
    cout<<cnt<<endl;
    return 0;
}
