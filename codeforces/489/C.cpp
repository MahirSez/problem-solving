#include<bits/stdc++.h>
using namespace std;
int n ,s;
int main()
{
    string mx ="" , mn = "";
    cin>>n>>s;
    int tmp = s;
    if(  9*n < s ) {
        cout<<-1<<" "<<-1<<endl;
        return 0;
    }
    if( s== 0 ) {
        if( n == 1)  {
            cout<<0<<" "<<0<<endl;
            return 0;
        }
        else {
            cout<<-1<<" "<<-1<<endl;
            return 0;
        }
    }

    for(int i =0 ; i < n ;i++) {

        if( tmp >=9) {
            mx +='9';
            tmp -=9;
        }
        else {
            mx += (char) ('0' + tmp);
            tmp = 0;
        }
    }
    mn = mx;
    reverse( mn.begin() , mn.end());

    if( mn[0] != '0') {
        cout<<mn<<" "<<mx<<endl;
        return 0;
    }
    for(int i =1; i<mn.size(); i++) {
        if( mn[i] != '0') {

            int tmp = mn[i] - '0';
            mn[0] = '1';
            tmp--;
            mn[i] = (char) ('0' + tmp);
            break;
        }
    }
    cout<<mn<<" "<<mx<<endl;
    return 0;
}
