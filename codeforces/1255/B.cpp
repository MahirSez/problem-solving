#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        int n , m;
        cin>>n>>m;
        vector<pii>vec(n);
        ll cst = 0;
        for(int i =0 ; i < n ; i++ ) {
            cin>>vec[i].uu ;
            vec[i].vv = i+1;
            cst += vec[i].uu;
        }
        
        if(m < n || n==2) {
            cout<<-1<<'\n';
            continue;
        }
        
        cst *=2;
        sort(vec.begin() , vec.end() );
        
        m -=n;
        int mm = m;
        while(m > 0) {
            cst += vec[0].uu + vec[1].uu;
            m--;
        }
        
        cout<<cst<<'\n';
        for(int i =1 ; i <n ; i++ ) {
            cout<<i<<" "<<i+1<<'\n';
        }
        cout<<1<<" "<<n<<'\n';
        
        while(mm>0) {
            cout<<vec[0].vv<<" "<<vec[1].vv<<'\n';
            mm--;
        }
        
    }
    return 0;
    
}