#include<bits/stdc++.h>
using namespace std;
string str1 , str2;
int dp[5000][5000] , n , m;

int solve(int id1 , int id2 ){
    if( id1 == n || id2 == m ) return 0;
    if( dp[id1][id2] != -1 ) return dp[id1][id2];
    int ans = 0;
    if( str1[id1] == str2[id2] ) ans = max(ans , 1 + solve(id1+1 , id2+ 1) );
    else ans = max( solve(id1+1 , id2) , solve(id1 , id2+1) );
    return dp[id1][id2] = ans;
}

string printLCS() {
    int id1 =0 , id2 = 0;
    string str ="";
    while( id1 < n && id2 < m ) {
        if( str1[id1] == str2[id2] ) {
            str += str1[id1];
            id1++;
            id2++;
        }
        else if( dp[id1+1][id2] > dp[id1][id2+1] ) id1++;
        else id2++;
    }
    return str;
}

int main()
{
    cin>>str1>>str2;
    n = str1.size();
    m = str2.size();
    memset( dp , -1 , sizeof dp);
    solve(0,0);
    cout<<printLCS()<<endl;
    return 0;
}

