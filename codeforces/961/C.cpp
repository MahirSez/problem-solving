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
int n ;
string ans[2][1000] ;
string cand[4][1000];
int ara[2][4];


int calc(int ansID , int candID) {

    string child[1000];
    string boss[1000];

    for(int i =0 ; i < n ;i++ ) {
        boss[i] = ans[ansID][i];
        child[i] = cand[candID][i];
    }
//
//    for(int i =0 ; i < n ;i++ )
//        cout<<boss[i]<<endl;
//    cout<<endl<<endl;
    int cnt= 0;

    for(int i =0 ; i < n ; i++ ) {

        for(int j =0 ; j < n ;j++ ) {

            if( child[i][j] != boss[i][j] )
                cnt++;
        }
    }

    ara[ansID][candID] = cnt;
    return cnt;
}

int main()
{
    fastRead;
    cin>>n;

    for(int  i=0  ; i < n ;i++ ) {

        for(int j =0 ; j < n;j++ ) {

            if( ((i+j) & 1) ) ans[0][i]+='1' , ans[1][i] +='0';
            else ans[1][i] += '1' , ans[0][i] += '0';
        }
    }

    for(int i =0 ; i < 4 ; i++ ) {

        for(int ro = 0 ; ro < n ;ro++ ) {

            cin>> cand[i][ro];
        }
    }

    for(int i =0 ; i < 4 ; i++ ) {

        calc(0 , i);
        calc(1 , i);
    }

    int ans1 = INF;
    for(int i =0 ; i < 4 ; i++ ) {

        for(int j = i+1 ; j < 4 ; j++ ) {

            int cnt = ara[0][i] + ara[0][j] ;
            for(int k = 0 ; k < 4 ; k++ )
                if( k!= i && k!= j) cnt += ara[1][k];
            ans1 = min(cnt ,ans1);
        }
    }

    cout<<ans1<<endl;
    return 0;
}
