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
int t;
string str;
int s , b , d;
int  ss , bb, dd;

int main()
{
    fastRead;
    cin>>t;
    while(t-- ) {
        cin>>str;
        s =0;
        b = 0;
        d = 0;
        ss = 0;
        dd = 0;
        bb = 0;
        for(int i =0 ; i < str.size() ;i++ ) {
            if( str[i] >='0' && str[i] <='9') {
                d++;
                dd = 1;
            }
            else if( str[i] >= 'a' && str[i] <= 'z') {
                s++;
                ss = 1;
            }
            else {
                b++;
                bb = 1;
            }
        }

        if(ss + dd + bb == 3 ) {
            cout<<str<<endl;
            continue;
        }
        else if( ss + dd + bb == 2) {

            if( ss == 0) {

                if( d >=2 ) {

                    for(int i =0 ; i < str.size() ; i++ ) {
                        if( str[i] >='0' && str[i] <='9') {
                            str[i] = 'a';
                            break;
                        }
                    }
                }
                else {
                    for(int i =0 ; i < str.size() ; i++ ) {
                        if( str[i] >='A' && str[i] <='Z') {
                            str[i] = 'a';
                            break;
                        }
                    }
                }
            }


            else if( dd == 0 ) {
                if( s >=2 ) {

                    for(int i =0 ; i < str.size() ; i++ ) {
                        if( str[i] >='a' && str[i] <='z') {
                            str[i] = '1';
                            break;
                        }
                    }
                }
                else {
                    for(int i =0 ; i < str.size() ; i++ ) {
                        if( str[i] >='A' && str[i] <='Z') {
                            str[i] = '1';
                            break;
                        }
                    }
                }
            }
            else {
                if( d >=2 ) {

                    for(int i =0 ; i < str.size() ; i++ ) {
                        if( str[i] >='0' && str[i] <='9') {
                            str[i] = 'A';
                            break;
                        }
                    }
                }
                else {
                    for(int i =0 ; i < str.size() ; i++ ) {
                        if( str[i] >='a' && str[i] <='z') {
                            str[i] = 'A';
                            break;
                        }
                    }
                }
            }
            cout<<str<<endl;
            continue;
        }

        else {
            if( ss) {
                str[0] = 'A';
                str[1] = '1';
            }
            else if( bb) {
                str[0] = 'a';
                str[1] = '1';
            }
            else {
                str[0] = 'a';
                str[1] = 'A';
            }
            cout<<str<<endl;
        }

    }
    return 0;
}
