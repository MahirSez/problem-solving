#include<bits/stdc++.h>
#define MAX 1000006
using namespace std;

typedef long long int ll;
int ara[MAX] , n;
string str ;

vector<int>a , b , aOdd , aEv , bOdd , bEv;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>str;
    n = str.size();

    for(int i =0 ; i< n ; i++ ) {
        if( str[i] == 'a' ) {
            a.push_back(i);
            if( i&1 ) aOdd.push_back(i);
            else aEv.push_back(i);
        }
        else if( str[i] == 'b' ) {
            b.push_back(i);
            if( i&1 ) bOdd.push_back(i);
            else bEv.push_back(i);
        }
    }

    ll tot = 0 , odd =0;
    for(int i = 0 ;  i < a.size() ;i ++) {

        tot += (a.size() - i);
    }

    for(int i = 0 ;  i < b.size() ;i ++) {

        tot += (b.size() - i );
    }
    for(int i =0; i < aOdd.size() ; i++ ) {

        odd += (aOdd.size() - i);
    }
    for(int i =0; i < aEv.size() ; i++ ) {

        odd += (aEv.size() - i);
    }
    for(int i =0; i < bEv.size() ; i++ ) {

        odd += (bEv.size() - i);
    }
    for(int i =0; i < bOdd.size() ; i++ ) {

        odd += (bOdd.size() - i);
    }


    cout<<tot-odd<<" "<<odd<<'\n';
    return 0;
}
