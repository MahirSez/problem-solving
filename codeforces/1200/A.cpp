#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;


const int MAX = 1e6 + 6;

int n ;
int ara[20];
int main()
{
    fastRead;
    string str;
    cin>>n;
    cin>>str;
    
    for(int i =0 ; i < str.size() ; i++ ) {
        
        if( str[i] == 'L') {
//                cout<<i<<endl;
            
            for(int j =0 ; j < 10 ; j++ ) {
                if( ara[j] == 0) {
                    ara[j] = 1;
                    break;
                }
            }
        }
        else if( str[i] == 'R') {
            for(int j = 9 ; j >= 0 ; j--) {
                if(ara[j] == 0 ) {
                    ara[j] = 1;
                    break;
                }
            }
        }
        else {
            
            int id = str[i] - '0';
            ara[id] = 0;
        }
        
//        for(int i = 0 ; i < 10 ; i++ ) cout<<ara[i];
//        cout<<'\n';
    }
    for(int i = 0 ; i < 10 ; i++ ) cout<<ara[i];
    cout<<'\n';
    return 0;
}