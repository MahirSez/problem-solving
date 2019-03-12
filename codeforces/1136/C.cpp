#include<bits/stdc++.h>
using namespace std;
int n , m;
int a[600][600] , b[600][600];

int taken[600][600];
bool ok ;
vector<int>v1 , v2;


void go(int ro, int col) {

//	cout<<" - "<<ro<<" "<<col<<endl;
    taken[ro][col] = 1;
    v1.push_back(a[ro][col]);
    v2.push_back(b[ro][col]);

    if( ro > 0 &&  col < m -1 && taken[ro-1][col+1] == 0) go(ro - 1 , col + 1);
    if( col > 0 && ro < n -1 &&taken[ro+1][col-1] == 0) go(ro + 1 , col - 1);
}


void check(int ro , int col) {
	v1.clear();
	v2.clear();
    go(ro , col);


    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());
    if( v1 != v2 ) ok = false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n>>m;
    for(int i =0 ; i < n ; i++  ) {
		for(int j =0 ; j < m ; j++ ) {
			cin>>a[i][j];
		}
    }
    for(int i =0 ; i < n ; i++  ) {
		for(int j =0 ; j < m ; j++ ) {
			cin>>b[i][j];
		}
    }
    ok = true;

    for(int i =0 ; i < n ; i++) {
		for(int j  = 0 ; j < m ; j++ ) {
			if( taken[i][j]) continue;
            check(i , j);
		}
    }


	if(ok) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
