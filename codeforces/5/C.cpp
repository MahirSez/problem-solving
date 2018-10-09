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
string str;
int ara[MAX];
int cnt1 , cnt2;
stack<int>st;
int main()
{
    cin>>str;
    for(int i =0 ; i < str.size() ; i++ ) {
        if( str[i] == '(') st.push(i);
        else {
            if(st.empty()) continue;

            ara[st.top()] = 1;
            st.pop();
            ara[i] = 1;
        }
    }
    int cnt = 0, mx = 0;
    for(int i =0 ; i < str.size() ; i++ ) {
        if( ara[i] ==0 ) cnt =0;
        else cnt++;
        mx = max(cnt , mx);
    }
    int ans = 0;
    if( mx==0 ) {
        cout<<0<<" "<<1<<endl;
        return 0;
    }
    cnt = 0;
    for(int i =0 ; i < str.size() ; i++ ) {
        if( ara[i] ==0 ) cnt =0;
        else cnt++;
        if( cnt == mx) ans++;
    }
    cout<<mx<<" "<<ans<<endl;
    return 0;
}
