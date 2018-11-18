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
string str;
int ro , col , n;
int main()
{
    cin>>str;
    n = str.size();
    for(int i = 1 ; i <=5 ; i++ ) {
        int tmp = (n-1)/i + 1;
        if( tmp <= 20) {
            ro = i;
            col = tmp;
            break;
        }
    }

    cout<<ro<<" "<<col<<endl;
    int it = 0;
    int lft =ro*col - n;
    for(int i =0 ; i < ro ; i++ ) {
        if( lft >0) cout<<"*";
        for(int j = (lft>0) ? 1 : 0 ; j < col ; j++) {

            cout<<str[it++];
        }
        lft--;
        cout<<'\n';
    }
    return 0;
}
