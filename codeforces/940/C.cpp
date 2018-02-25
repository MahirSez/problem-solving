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
string str, ans;
int n , k;
char ara[MAX];
bool alpha[30];
vector<char>v;

int main()
{
    cin>>n>>k>>str;
//    cout<<str<<endl;
    for(int  i=0 ; i< str.size() ; i++ ) {

        if(alpha[str[i]-'a'] == false) {
            alpha[str[i]-'a'] = true;
            v.push_back(str[i]);
        }
    }
    sort(v.begin() , v.end() ) ;
    char ch = v[v.size() -1];
//    cout<<ch<<endl;
    if( k > n  ) {
        ans = str;
        for(int  i=n ; i <k;i++  )
            ans += v[0];
        cout<<ans<<endl;
        return 0;
    }
//    cout<<ch<<endl;
    for(int  i = k-1 ; i >=0 ; i-- ) {
//        cout<<ch<<endl;
        if( str[i] == ch ) ara[i] = v[0];
        else {
//            cout<<ch<<endl;

            for(int  j=0 ; j < v.size() ; j++ ) {

                if( v[j] > str[i] ) {
                    ara[i] = v[j];
                    break;
                }
            }

            for(int j = i-1 ; j >= 0 ; j-- ) ara[j] = str[j];
            break;
        }
    }
//    cout<<"here"<<endl;
    cout<<ara<<endl;
    return 0;
}
