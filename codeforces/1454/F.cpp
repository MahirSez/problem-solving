#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define tp          tuple<int,int,int>
#define fastio      ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int tree[4*N], ara[N];
vector<int>rec[N];
int n;

void build(int node, int l, int r) {
    if( l== r) {
        tree[node] = ara[l];
        return;
    }
    int mid = (l+r)/2;
    build(node<<1, l , mid);
    build(node<<1|1, mid+1 , r);
    tree[node] = min(tree[node<<1] , tree[node<<1|1]);
}

int query(int node, int l ,int r, int frm , int to) {
    if(l > r || l > to || r < frm ) return INF;
    if(l >= frm && r <= to) return tree[node];
    int mid = (l+r)/2;
    int q1 = query(node<<1, l, mid, frm, to);
    int q2 = query(node<<1|1, mid+1, r, frm, to);
    return min(q1, q2);
}   

/*
1
7
4 2 1 1 4 1 4
*/

int solve(int l ,int r, int tgt) {
    if(l <= 1 || r >= n) return -1;

    
    int cnt1 = 0 , cnt2 = 0 ;
    for(auto x : rec[tgt]) {
        if( x < l) cnt1++;
        if(x > r) cnt2++;
    }
    // cout<<l<<" "<<r<<" --- "<<cnt1<<" "<<cnt2<<'\n';
    if(cnt1 == 0 || cnt2 == 0 ) return -1;

    int mn = query(1 ,1 , n , l , r);

    
    if(mn == tgt) {
        // cout<<"sol "<<l<<" "<<r<<"\n";
        return l-1;
    }
    return -1;

}

int main() {
    fastio;

    int t;
    cin>>t;
    while(t--) {
    
        
        cin>>n;
        map<int,int>mp;
        for(int i = 1 ;i <= n; i++) {
            cin>>ara[i];
            mp[ara[i]] = 1;
        }
        int cnt = 0;
        for(auto &x : mp) x.vv = ++cnt;

        for(int i = 1; i <= n ;i++ ) ara[i] = mp[ara[i]];
        for(int i = 1 ; i <= cnt ; i++) rec[i].clear();

        for(int i =1; i<= n ; i++ ) rec[ara[i]].push_back(i);

        build(1 ,1 , n);

        bool ok = 0;
        int id = -1;

        if(rec[cnt].size() >= 3) {
            cout<<"YES\n";
            int id = rec[cnt][1]-1;
            cout<<id<<" "<<1<<" "<<n-id-1<<'\n';
            continue;
        }
        
        

        int l = n+1 , r = 0;


        for(int i = cnt -1 ; i >= 1 ; i--) {
            l = min(l, rec[i+1][0]);
            r = max(r, rec[i+1].back());

            if(rec[i].size() <3) continue;

            id = solve( l , r , i);
            
            if(id !=-1) {
                
                ok = 1;

                int len = r - l + 1;
                int left = n - len - id;
                cout<<"YES\n";
                cout<<id<<" "<<len<<" "<<left<<'\n';
                break;
            }
            id = solve( l-1 , r , i);
            if(id !=-1) {
                ok = 1;

                int len = r - l + 2;
                int left = n - len - id;
                cout<<"YES\n";
                cout<<id<<" "<<len<<" "<<left<<'\n';
                break;
            }
            id = solve( l , r+1 , i);
            if(id !=-1) {
                ok = 1;

                int len = r - l + 2;
                int left = n - len - id;
                cout<<"YES\n";
                cout<<id<<" "<<len<<" "<<left<<'\n';
                break;
            }                        
        }


        if(!ok) cout<<"NO\n";
        
    }
    return 0;
}



