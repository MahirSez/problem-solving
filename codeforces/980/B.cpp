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
int col , ara[200][200] , blk;
void printLn() {

    for(int  i =0 ; i < col ; i++) cout<<".";
        cout<<endl;
}
void printEv(int tmp) {

    cout<<".";
    for(int i =0 ; i < tmp ;i ++ ) cout<<"#";
    for(int i = tmp + 1; i < col ; i++ ) cout<<".";
    cout<<endl;
}
void printOdd(int tmp) {
    for(int i= 0; i <  (col/2 - tmp/2 ); i++) cout<<".";
    for(int i =0 ; i < (tmp/2 ) ; i++ ) cout<<"#";
    cout<<"#";
    for(int i =0 ; i < (tmp/2 ) ; i++ ) cout<<"#";
    for(int i= 0; i <  (col/2 - tmp/2 ); i++) cout<<".";
    cout<<endl;
}

void printOdd1(int tmp) {

    cout<<".";
    for(int i =0 ; i < tmp/2; i++ ) cout<<"#";
    for(int i = tmp/2 + 1; i < col/2 ; i++ ) cout<<".";
    cout<<".";
    for(int i = tmp/2 + 1; i < col/2 ; i++ ) cout<<".";
    for(int i =0 ; i < tmp/2; i++ ) cout<<"#";
    cout<<"."<<endl;
}

int main()
{
    cin>>col>>blk;
    if( blk %2 == 0) {

        cout<<"YES"<<endl;
        printLn();
        printEv(blk/2);
        printEv(blk/2);
        printLn();
    }
    else {

        cout<<"YES"<<endl;
        printLn();
        printOdd(min(blk , col-2) );
        blk  = max( 0 , blk - (col-2) );
        printOdd1(blk);
        printLn();
    }

    return 0;
}
