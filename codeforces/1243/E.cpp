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

ll n , ara[MAX] , box[MAX] , to[MAX] , dp[MAX] ;
vector<ll> ans[MAX];
map<ll,int>mp;

ll tot[MAX];

ll ret[MAX] , dest[MAX];

int main()
{
    fastRead;
    cin>>n;
    int cnt = 0;
    
    ll sum = 0;
    for(int i = 0 ; i < n ; i++ ) {
        
        int k;
        cin>>k;
        while(k--) {
            ll tmp;
            cin>>tmp;
            ara[++cnt] = tmp;
            mp[tmp] = cnt;
            box[cnt] = i;
            sum += tmp;
            
            tot[i] += tmp;
        }
    }

    if(sum%n) {
        cout<<"No\n";
        return 0;
    }
    
    ll per = sum/n;
    
    
    for(int i= 1 ; i <=cnt ; i++ ) {
        
        ll num = ara[i];
        
//        ll sum = 0;
//        for(int j = 1 ; j <= cnt ; j++) {
//            
//            if(box[i] == box[j]) sum += ara[j];
//        }
        ll tgt = per - tot[box[i]] + num;
        

        if(mp.count(tgt) == 0 ) continue;
        
        to[i] = mp[tgt];
        

    }

    
    for(int i =1 ; i <=cnt ; i++ ) {
        
        
        int frm = i;
        int mask = 0;
        bool ok = false;
//        cout<<num<<" -> "<<frm<<'\n';
        
        while(1) {
            
            mask |= (1<<box[frm]);
            
            frm = to[frm];
            
            if(frm == 0 )  break;
            
//            cout<<frm<<'\n';
            
            if(ara[frm] == ara[i]) {
                ok = true;
                break;
            }
            
            if(mask & (1<<box[frm])) break;
        }
        
        if(ok) {
//            cout<<"yayy "<<mask<<'\n';
            if(dp[mask] == 0 ) {
                dp[mask] = 1;
                ans[mask].push_back(i);
            }
        }
        
//        cout<<"------------\n";
    }
    
    
    dp[0] = 1;
    
    for(int mask = 0 ; mask < (1<<n) ; mask ++ ) {
        
//        if(dp[mask]) continue;
        for(int sub = mask ; sub > 0 ; sub = ( (sub-1)&mask)   ) {
            
            int other = mask ^sub;
            if(dp[sub] && dp[other] ) {
                
                dp[mask] = 1;
                
                ans[mask] = ans[sub] ;
                for(auto x : ans[other]) ans[mask].push_back(x);
//                break;
            }
        }
    }
    
    if(dp[(1<<n)-1] == 0 ) {
        cout<<"No\n";
        return 0;
    }
    
    cout<<"Yes\n";
    for(auto x : ans[(1<<n)-1]) {
        
        int frm = x;
        
        while(1) {
//            cout<<box[frm]<<" ";
            
            int boxid = box[frm];
            
            ret[boxid] = ara[frm];
            
            dest[box[to[frm]]] = boxid;
            
            frm = to[frm];
            
            if(frm == x) break;
        }
//        cout<<'\n';
        
    }
    
    for(int i =0 ; i < n ; i++ ) {
        cout<<ret[i]<<" "<<dest[i]+1<<'\n';
    }
    return 0;
}
