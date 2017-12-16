#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS		1e-8
#define MAX		1000006
using namespace std;
int n , a , b;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>a>>b;
    int tmp = gcd(a,b);
    if( n % tmp)  {
        cout<<"NO"<<endl;
        return 0;
    }

    if( n%a == 0 ) {
        cout<<"YES"<<endl;
        cout<<(n/a) <<" "<<0<<endl;
        return 0;
    }
    if( n % b ==0 ){
            cout<<"YES"<<endl;
        cout<<0<<" "<<(n/b)<<endl;
        return 0;
    }
    if( n==0 ) {
        cout<<"YES"<<endl;
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    for( int  i = 0 ;  (b*i) <=n ;i++) {

        if( ( n - b*i ) %a ==0 ){
            cout<<"YES"<<endl;
            cout<<( (n - b * i) /a)<<" "<<i <<endl;
            return 0;
        }
    }
    for( int  i = 0 ;  (a*i) <=n ;i++) {

        if( ( n - a*i ) %b ==0 ){
            cout<<"YES"<<endl;
            cout<<i<<" "<< ( (n - a * i) /b)<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
