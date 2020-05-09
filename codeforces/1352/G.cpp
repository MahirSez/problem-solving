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
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        if(n <=3 ) {
            cout<<-1<<'\n';
            continue;
        }
        int frm = n;
        if(frm%2==0) frm--;
        
        while(frm > 0) {
            cout<<frm<<" ";
            frm-=2;
        }
        
        cout<<4<<" "<<2<<" ";
        
        for(int i = 6 ; i <=n ; i +=2) cout<<i<<" ";
        cout<<'\n';
    }
    return 0;
}