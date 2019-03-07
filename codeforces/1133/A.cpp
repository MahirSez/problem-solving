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
string str1 , str2;
int h1 , h2 , m1 , m2;
int main()
{
    cin>>str1>>str2;
    bool ok = false;
    for(int i =0 ; i < (int)str1.size() ; i++ ) {
        if( str1[i]==':') {
            ok = true;
            continue;
        }
        if( ok ) {
            m1 = (m1 *10 + (str1[i]-'0') );
        }
        else {
            h1 = (h1 *10 + (str1[i]-'0') );
        }
    }
     ok = false;
    for(int i =0 ; i < (int)str2.size() ; i++ ) {
        if( str2[i]==':') {
            ok = true;
            continue;
        }
        if( ok ) {
            m2 = (m2 *10 + (str2[i]-'0') );
        }
        else {
            h2 = (h2 *10 + (str2[i]-'0') );
        }
    }
    int hGap = h2 - h1;

    int minGap = hGap * 60 + m2 - m1;
    minGap/=2;

    minGap = h1 *60 + m1 + minGap;
    h1 =minGap/60;
    m1 =minGap%60;
    

    // if( h1 ==0 ) cout<<"0";
    // else if( h1/10 ==0 ) cout<<0;
    // cout<<h1<<":";
    
    // if( m1 ==0 ) cout<<"0";
    // else if( m1/10 ==0 ) cout<<0;
    // cout<<m1;
    // cout<<endl;


    if( h1/10 ==0) cout<<0;
    cout<<h1<<":";
    if( m1/10==0) cout<<0;
    cout<<m1<<endl;
    
    return 0;
    
}