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

vector<pii>vec[MAX] ;
map<pii , vector<int> >mp;
int fre[MAX] , vis[MAX];
int main()
{
    fastRead;
    
    int n;
    cin>>n;
    for(int i =0 ; i < n -2 ; i++ ) {
        
        int a , b , c;
        cin>>a>>b>>c;
        fre[a]++;
        fre[b]++;
        fre[c]++;
        
        vec[a].push_back({b,c});
        vec[b].push_back({c,a});
        vec[c].push_back({b,a});
        
        mp[{a,b}].push_back(c);
        mp[{b,a}].push_back(c);
        
        mp[{b,c}].push_back(a);
        mp[{c,b}].push_back(a);
        
        mp[{a,c}].push_back(b);
        mp[{c,a}].push_back(b);
    }
    
    int id1 = -1 , id2 = -1;
    for(int i =1; i <=n ; i++ ) if(fre[i] == 1) id1 = i;
    assert(id1 != -1);
    
    for(auto x : vec[id1]) {
        if(fre[x.uu] == 2) id2 = x.uu;
        if(fre[x.vv] == 2) id2 = x.vv;
    }
    
    assert(id2 != -1);
    
    cout<<id1<<" "<<id2<<" ";
    vis[id1] = vis[id2] =1;
    int cnt = 2;
    
    while(cnt < n ) {
        
        for(auto x : mp[{id1,id2}]) {
            
            if(vis[x] ==0 ) {
                cout<<x<<" ";
                vis[x] = 1;
                id1 = id2;
                id2 = x;
                cnt++;
                break;
            }
        }
    }
    
    cout<<'\n';
    return 0;
    
    
}