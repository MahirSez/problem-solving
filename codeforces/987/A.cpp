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

map<string,int>mp;
int main()
{
    int n;
    cin>>n;
    string ara1[] = {"purple", "green", "blue", "orange", "red", "yellow"};
    string ara2[] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};
    for(int i =0 ; i < n ; i++) {
        string str;
        cin>>str;
        mp[str] = 1;
    }
    cout<<6-n<<endl;
    for(int i =0 ; i < 6; i++ ) {
        if( mp[ara1[i]] ==0 ) {
            cout<<ara2[i]<<endl;
        }
    }
    return 0;
}
