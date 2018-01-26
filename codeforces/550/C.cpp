#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS     1e-8
#define MAX     1000006
#define MOD     1000000007
using namespace std;
string str;
int main()
{
    cin>>str;
    for( int k = 0 ; k < str.size() ; k++ ) {

        if( (  (str[k] - '0') ) %8 ==0 ) {
            cout<<"YES"<<endl;
            cout<<str[k]<<endl;
            return 0;
        }
    }
     for( int  j =0; j < str.size(); j++ ) {

        for( int k = j +1 ; k < str.size() ; k++ ) {

            if( (  (str[j]-'0')*10 + (str[k] - '0') ) %8 ==0 ) {
                cout<<"YES"<<endl;
                cout<<str[j]<<str[k]<<endl;
                return 0;
            }
        }
    }
    for( int  i =0 ; i < str.size() ; i++ ) {

        for( int  j =i+1; j < str.size(); j++ ) {

            for( int k = j +1 ; k < str.size() ; k++ ) {

                if( ( (str[i]-'0')*100 + (str[j]-'0')*10 + (str[k] - '0') ) %8 ==0 ) {
                    cout<<"YES"<<endl;
                    cout<<str[i]<<str[j]<<str[k]<<endl;
                    return 0;
                }
            }
        }
    }




    cout<<"NO"<<endl;
    return 0;
}
