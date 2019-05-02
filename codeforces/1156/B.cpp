#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n;
string str;



int main()
{
    fastRead;
    cin>>n;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    while( n-- ) {


		cin>>str;

		vector<char>v;
		map<char,int>mp;

		for(int i =0 ;i < str.size() ; i++ ) {

			mp[str[i]]++;
		}

		for(auto x : mp) v.push_back(x.uu);

		bool ok = true;

        for(int i =0 ; i < 1000 ; i++ ) {

            shuffle(v.begin() , v.end() , rng);

			ok = true;
            for(int j =1 ; j < v.size() ;j++ ) {

				if( abs(v[j] - v[j-1] )== 1 ){
					ok= false;
					break;
				}
            }
            if( ok) break;
        }

        if( !ok) {
			cout<<"No answer\n";
			continue;
        }
		for(auto x : v) {
            int cnt = mp[x];
            while( cnt--) cout<<x;
		}
		cout<<'\n';
    }

    return 0;
}
