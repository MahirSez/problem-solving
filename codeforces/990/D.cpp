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
int ara[2000][2000] , n , a , b;

void print() {
    for(int i =1 ; i<= n ;i++ ) {
        for(int j = 1; j<=n ; j++ ) {
            if( i==j) cout<<0;
            else cout<<ara[i][j];
        }
        cout<<endl;
    }
}

int main()
{
    cin>>n>>a>>b;

    if( a== 1 && b ==1) {
        if( n==1) {
            cout<<"YES"<<endl;
            cout<<0<<endl;
        }
        else if( n <=3) {
            cout<<"NO"<<endl;
        }
        else  {
            cout<<"YES"<<endl;
            for(int i =1 ; i <= n ;i++ ) {
                for(int j= 1; j <= n ;j++) {
                    if( abs(i-j)==1 ) cout<<1;
                    else cout<<0;
                }
                cout<<endl;
            }
        }
        return 0;
    }
    if(a!= 1 && b !=1 ) {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    if (a != 1 ) {

        for(int i =2 ; i <= n- a+1 ;i++ ) {
            ara[1][i] = 1;
            ara[i][1] = 1;
        }
        print();
        return 0;
    }
    for(int i =2 ; i<= n- b+1 ;i++) {
        ara[i][1] = 1;
        ara[1][i] = 1;
    }
    for(int i = 1 ; i<= n ; i++ ) {
        for(int j =1 ;j <= n ;j++ ) {
            if( i ==j ) cout<<0;
            else if( ara[i][j] == 1) cout<<0;
            else cout<<1;
        }
        cout<<endl;
    }
    return 0;
}
