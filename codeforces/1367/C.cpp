#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int n, k;

int brute() {
    int ans = 0;
    for(int i =0 ; i < n ; i+=k) ans++;
    return ans;
}

int get1(int frm) {
    
    int ans = 0;
    for(int i = frm- k ; i >=0 ; i-=k) ans++;
    return ans;
}

int get2(int frm) {
    
    int ans = 0;
    for(int i = frm + k ; i < n ; i+=k) ans++;
    return ans;
}

int get(int frm,int to) {
    int ans = 0;
    for(int i = frm + k ; i + k<=to ; i += k) {
        ans++;
    }
    return ans;
}

int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {

        cin>>n>>k;
        k++;
        vector<int>ones;
        string str;
        cin>>str;
        for(int i =0 ; i < n ; i++ ) {
            if(str[i] =='1') ones.push_back(i);
        }
        if(ones.size() == 0) {
            cout<<brute()<<'\n';
            continue;
        }
        int ans = 0;        
        ans += get1(ones[0]);
        ans += get2(ones.back());
        
        for(int i = 0; i < ones.size()-1 ; i++ ) {
            ans += get(ones[i], ones[i+1]);
        }
        
        cout<<ans<<'\n';
    }
    return 0;
}