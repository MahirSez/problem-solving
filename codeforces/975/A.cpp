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
int n;
string s;
map<char, bool>mp;
bool used[30];
set<string>st;
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        mp.clear();
        cin>>s;
        string tm = "";
        for(int j =0 ; j < s.size() ; j++ ) {

            if( mp[s[j]] == false) {
                tm+=s[j];
                mp[s[j]] = true;
            }
        }
        sort(tm.begin(), tm.end() );
        st.insert(tm);
    }
    cout<<st.size()<<endl;
    return 0;
}
