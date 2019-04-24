#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("dull.in","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	10000007
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int x;
vector<int>v;

bool ok(int tmp) {

    while( tmp) {
        if( tmp%2 ==0 ) return false;
        tmp/=2;
    }
    return true;
}

int get(int tmp) {

	int cnt = 0;
	while( tmp ) {
        tmp/=2;
        cnt++;
	}
	return cnt;
}

int main()
{


    cin>>x;
	int cnt = 0;


    while(!ok(x) ) {

		cnt++;

		if( cnt %2==0 ) {
            x++;
            continue;
		}


        int getMsb = get(x);

        int mask = (1<<getMsb)-1;


        v.push_back(getMsb);
        x ^=mask;

//        cout<<x<<endl;

    }

    cout<<cnt<<endl;
    for(auto x : v) cout<<x<<" ";
    cout<<endl;
    return 0;
}
