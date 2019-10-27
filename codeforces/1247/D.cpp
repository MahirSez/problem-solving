#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const ll MAX = 1e5 + 5;
int mark[MAX];
vector<int>prm;

void seive() {

    for(ll i = 2; i *i <MAX ; i++ ) {
        
        if(mark[i]) continue;
        
        for(int j = i*i ; j < MAX ; j+=i) {
            
            mark[j ] =1;
        }
    }
    for(int i =2;  i < MAX ; i++ ) {
        if(mark[i] == 0) prm.push_back(i);
    }
}
int n , k , sz , ara[MAX];

map< map<int , int> , int>mp;

int main()
{
    seive();

    cin>>n>>k;
    
    sz = prm.size();
    
    for(int i =0 ; i < n ; i++ ) cin>>ara[i];
    
    ll ans = 0;
    for(int i =0 ; i < n ; i++ ) {
        
        
        int tmp = ara[i];
        map<int,int>vec;
        map<int,int>tgt;
        
        for(int j =0 ; j < sz&& tmp > 1 ; j++ ) {
            
            int cnt = 0;
            while(tmp%prm[j] == 0) {
                tmp/=prm[j];
                cnt++;
            }
            cnt %=k;
            
            if(cnt ) {
                vec[j] = cnt;
                tgt[j] = k - cnt;
            }
        }
        
        ans += mp[tgt];
        mp[vec]++;
        
//        cout<<ara[i]<<" -> \n";
//        for(int j =0 ; j < 10 ; j++ ) {
//            cout<<prm[j]<<" "<<vec[j]<<'\n';
//        }
        
    }
    
    cout<<ans<<'\n';
    
    return 0;
}
