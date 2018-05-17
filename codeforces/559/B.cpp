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
string str1 , str2;
map<string , map<string ,int> > mp;

int solve(string s1 , string s2) {

    if( s1 == s2) return 1;
    if( ((int)s1.size())&1 ) return 0;
    if( mp[s1][s2] ) return 1;
    string s11 = s1.substr(0 , s1.size()/2);
    string s12 = s1.substr(s1.size()/2 , s1.size()/2);
    string s21 = s2.substr( 0 , s2.size() /2);
    string s22 = s2.substr(s2.size()/2 , s2.size()/2);
    if( (solve(s11 , s21) && solve(s12,s22)) || (solve(s11 , s22) && solve(s12,s21) ) )
        return mp[s1][s2] = mp[s2][s1] = 1;
    return 0;
}

int main()
{
    cin>>str1>>str2;
    if( solve(str1, str2)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
