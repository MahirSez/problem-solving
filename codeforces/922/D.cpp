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
int n;
vector<string>v;
string str;

bool cmp(string strr1 , string strr2) {
    string str1 = strr1 + strr2;
    string str2 = strr2 + strr1;
    ll s1= 0, s2 = 0, t1= 0 ,t2 = 0;
    for(int i =0 ; i < str1.size() ; i++) {
        if( str1[i] == 's') s1++;
        else t1 += s1;
    }
    for(int i =0 ; i < str2.size() ; i++) {
        if( str2[i] == 's') s2++;
        else t2+=s2;
    }
    return (t1 > t2);
}

int main()
{
    cin>>n;
    for( int  i= 0 ; i < n ;i++ ) {
        cin>>str;
        v.push_back(str);
    }

    sort(v.begin() ,v.end() , cmp);
    string fin ="";

    for(int  i =0 ; i< n ; i++ )
        fin += v[i];

    ll ans = 0, s= 0;
    for( int  i =0 ; i < fin.size(); i++ ) {

        if( fin[i] == 's') {
            s++;
        }
        else ans += s;
    }

    cout<<ans<<endl;
    return 0;
}
