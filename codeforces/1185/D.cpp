#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("in.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("out.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n  ;
map<ll,int> cnt;
pii ara[MAX] ;
set<int>st;


void print() {

    for(auto x:st) {
        cout<<x<<" ";
        
    }
    cout<<endl;
}
int main()
{
    fastRead;
    cin>>n;
    for(int i =1 ; i <=n ; i++ ) {
        int tmp;
        cin>>tmp;
        ara[i].uu = tmp;
        ara[i].vv = i;
    }
    
    sort(ara+1 ,ara + n+1);
    
    
    for(int i =2 ; i <= n ; i++ ) {
        st.insert(ara[i].uu - ara[i-1].uu);
        cnt[ara[i].uu - ara[i-1].uu]++;
    }
    
    for(int i = 1; i <= n ; i++ ) {
        
        
        int tmp1 = 0 , tmp2 = 0;
        
        if(i > 1 ) {
            tmp1 = ara[i].uu - ara[i-1].uu;
            cnt[tmp1]--;
            if(cnt[tmp1] == 0) st.erase(tmp1);
        }
        
        if( i < n ) {
            tmp2 = ara[i+1].uu - ara[i].uu;
            cnt[tmp2]--;
            if( cnt[tmp2] == 0 ) st.erase(tmp2);
        }
        
//        cout<<ara[i].uu<<" "<<tmp1<<" "<<tmp2<<endl;
        
        if(i >1 && i < n ) st.insert(tmp1+ tmp2);
        
        if( st.size() <=1 ) {
//            cout<<ara[i].uu<<endl;
            cout<<ara[i].vv<<"\n";
            return 0;
        }
        if(i >1 && i < n )st.erase(tmp1+tmp2);
        
        if( i > 1) {
            cnt[tmp1]++;
            st.insert(tmp1);
        }
        if( i < n ) {
            cnt[tmp2]++;
            st.insert(tmp2);
        }
        
//        print();
    }
    cout<<-1<<'\n';
    return 0;
}


/*
5
4 4 4 5 4
*/