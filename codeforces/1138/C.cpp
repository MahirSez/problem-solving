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
int n , m;
int ara[2000][2000];
int roMx[2000] , colMx[2000];
vector<int>ro[2000] , col[2000];
map<int,int>mp;
int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < n ; i++ ) {
		for(int j =0 ; j < m ; j++ ) {
			cin>>ara[i][j];
		}
    }

    for(int i =0 ; i < n ; i++ ) {

		vector<int>v;
		mp.clear();

        for(int j =0 ; j < m ; j++ ) {
			v.push_back(ara[i][j]);
        }
        sort(v.begin() , v.end() ) ;

        int cnt= 0;

        for(int j =0 ; j < m ; j++ ) {
			if( mp.count(v[j]) == 0) mp[v[j]] = ++cnt;
        }
        roMx[i] = cnt;

        for(int j =0 ; j < m ; j++) {
			ro[i].push_back(mp[ara[i][j]]);
        }
    }

    for(int j =0 ; j < m ; j++ ) {

		vector<int>v;
		mp.clear();

        for(int i =0 ; i < n ; i++ ) {
			v.push_back(ara[i][j]);
        }
        sort(v.begin() , v.end() ) ;

        int cnt= 0;

        for(int i =0 ; i < n ; i++ ) {
			if( mp.count(v[i]) == 0) mp[v[i]] = ++cnt;
        }
        colMx[j] = cnt;

        for(int i =0 ; i < n ; i++) {
			col[i].push_back(mp[ara[i][j]]);
        }
    }

//    for(int i =0 ; i < n ; i++ ) {
//		cout<<colMx[i]<<endl;
//    }
//    cout<<endl;
//


	for(int i =0 ; i < n ; i++ ) {

		for(int j =0 ; j < m ; j++ ) {

            int roVal = ro[i][j];
            int colVal = col[i][j];

            int roMax = roMx[i];
            int colMax = colMx[j];

//            cout<<i<<" "<<j<<"-- "<<roVal<<" "<<colVal<<" "<<roMax<<" "<<colMax<<endl;

			int extra = abs(roVal - colVal);

            if( roVal > colVal) {
                cout<<max(roMax , colMax + extra)<<" ";
            }
            else {
                cout<<max(roMax +extra, colMax)<<" ";
            }


		}
		cout<<'\n';
	}



	return 0;
}
