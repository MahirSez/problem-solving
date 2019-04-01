#include<bits/stdc++.h>
using namespace std;
int n , ara[200];
int solve(int frm , int len) {

	bool ok = true;

    for(int i = frm+1 ,cnt = 1; cnt < len ; i++ , cnt++) {
		if( ara[i] < ara[i-1] ) {
			ok = false;
		}
    }
    if( ok ) return len;

    return max(solve(frm , len/2) , solve(frm + len/2 , len/2) );
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

    cin>>n;
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    cout<<solve(0 , n)<<endl;
    return 0;
}
