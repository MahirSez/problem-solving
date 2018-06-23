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
string s1 , s2;
int n;
int main()
{
    cin>>s1>>s2;
    s1 += 'X';
    s2 += 'X';
    int cnt = 0;
    for(int i = 0 ; i < s1.size()-1 ; i++ ) {
        if(s2[i] == '0' && s1[i] == '0' && s1[i+1]=='0') {
            cnt++;
            s2[i] = 'X';
            s1[i] = 'X';
            s1[i+1] = 'X';
        }
        else if( s1[i] == '0' && s2[i] == '0' && s2[i+1]=='0') {
            cnt++;
            s1[i] = 'X';
            s2[i] = 'X';
            s2[i+1] = 'X';
        }
        else if( s1[i] == '0' && s2[i+1] == '0' && s1[i+1] =='0') {
            cnt++;
            s1[i] = 'X';
            s2[i+1] = 'X';
            s1[i+1] = 'X';
        }
        else if( s2[i] =='0' && s1[i+1] =='0' && s2[i+1] == '0' ) {
            cnt++;
            s2[i] = 'X';
            s1[i+1] = 'X';
            s2[i+1] = 'X';
        }
    }
    cout<<cnt<<endl;
    return 0;
}
