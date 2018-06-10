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

int n;
map<int , ll>mp;
vector<int>v;

void process(string str) {
    int lft = 0 , rt = 0 ;

    for(int i =0 ; i < str.size() ; i++) {
        if( str[i] == '(') lft++;
        else if( str[i] ==')') {
            if( lft) lft--;
            else rt++;
        }
    }
    if( lft && rt ) return ;

    if( lft ==0 && rt == 0 )  {
        if( mp[0] == 0) v.push_back(0);
        mp[0]++;
    }
    else if( lft ) {
        if( mp[-lft]==0 ) v.push_back(-lft);
        mp[-lft]++;
    }
    else {
        if( mp[rt] ==0) v.push_back(rt);
        mp[rt]++;
    }

}


int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ;i++ ) {
        string str;
        cin>>str;
        process(str);
    }
    ll ans =0;
    for(int i =0 ; i< v.size() ; i++ ) {
        int tmp = v[i];
        ans += (mp[tmp] * mp[-tmp]);
        mp[-tmp] = 0;
        mp[tmp]= 0;
    }
    cout<<ans<<endl;
    return 0;
}

