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
int n;
string str;
map<string,int>mp;
int main()
{
    cin>>n>>str;
    string kop ="";
    int ans = 0 ;
    for(int i =0 ; i < n-1 ;i++ ) {

        string tmp = "";
        tmp += str[i];
        tmp += str[i+1];
        mp[tmp]++;
        if( mp[tmp]  > ans) {
            kop = tmp;
            ans = mp[tmp];
        }
    }
    cout<<kop<<endl;
    return 0;
}
