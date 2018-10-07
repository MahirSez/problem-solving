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
string str ;
int cnt;
map<char , int>mp;
stack<int>st;
map<bool , int>ase;
int main()
{
    cin>>str;
    mp['('] =1;
    mp['<'] =2;
    mp['{'] =3;
    mp['['] =4;

    mp[')'] =-1;
    mp['>'] =-2;
    mp['}'] =-3;
    mp[']'] =-4;
    int ans = 0;
    for(int i =0 ; i < str.size() ; i++ ) {
        char ch = str[i];
        if( mp[ch] > 0) {
            cnt++;
            st.push(mp[ch]);
        }
        else {
            cnt--;

            if( cnt < 0) {
                cout<<"Impossible"<<endl;
                return 0;
            }

            if( st.top() != -mp[ch] ) {
                ans++;
            }
            st.pop();
        }

    }
    if( cnt) {
        cout<<"Impossible"<<endl;
    }
    else {
        cout<<ans<<endl;
    }
    return 0;


}
