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
map<pii , vector<string> > mp1;
vector<string>mp3[MAX];

map<string , int>mp2;
vector<string>vec;
vector<pii>pstr;
int rec[100];

vector<int>numstr;


vector<pair<string,string> > ansone , anstwo , ans;
int n;

pii get(const string& s ){
    
    int u = 0  , v  = -1;
    for(int i =0 ; i <s.size() ; i++  ) {
        if( rec[s[i] - 'a']) {
            u++ ;
            v = s[i]-'a';
        }
    }
    return {u,v};
    
}
int get1(const string& s ){
    
    int u = 0  ;
    for(int i =0 ; i <s.size() ; i++  ) {
        if( rec[s[i] - 'a']) {
            u++ ;
        }
    }
    return u;
    
}

int main()
{
    
    fastRead;
    rec[0] = 1;
    rec['e' -'a'] = 1;
    rec['i' -'a'] = 1;
    rec['o' -'a'] = 1;
    rec['u' -'a'] = 1;
    
    
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        string str;
        cin>>str;
        vec.push_back(str);
        mp2[str]++;
    }

    
    for(auto x : vec) {
        
        pii p = get(x);
        if(mp1[p].size() ==0 ) pstr.push_back(p);
        mp1[p].push_back(x);
        
    }
    
    for(auto x : pstr) {
        
        int sz = mp1[x].size();
        
        for(int i =1 ; i <sz ; i+=2 ) {
            
            ansone.push_back({mp1[x][i-1] , mp1[x][i]});
            mp2[mp1[x][i]]--;
            mp2[mp1[x][i-1]]--;
        }
    }
    
//    for(auto x:ansone) {
//        cout<<" "<<x.uu<<" "<<x.vv<<endl;            
//    }
//    
//    for(auto x : vec) {
//        cout<<x<<" "<<mp2[x]<<endl;
//    }
//    return 0;
    
    for(auto x: vec) {
        
        if( mp2[x] ==0  ) continue;
        
        int cnt = get1(x);
        
        
        
        mp2[x]--;
        
        if( mp3[cnt].size() == 0 ) numstr.push_back(cnt);
        
        mp3[cnt].push_back(x);
    }
    
    for(auto x : numstr) {
        
        int sz = mp3[x].size();
        
        for(int i =1 ; i < sz ; i+=2 ) {
            anstwo.push_back({mp3[x][i-1] , mp3[x][i]});
        }
    }
    
    
    int sz1 = ansone.size();
    int sz2 = anstwo.size();
    
    int i ;
    for(i =0 ; i < min(sz1 , sz2 ) ; i++ ) {
        
        ans.push_back({anstwo[i].uu , ansone[i].uu});
        ans.push_back({anstwo[i].vv , ansone[i].vv});
        
    }
    
    for( ; i +1< sz1 ; i+=2 ) {
        ans.push_back({ansone[i].uu, ansone[i+1].uu} );
        ans.push_back({ansone[i].vv, ansone[i+1].vv} );
    }
    
    cout<<ans.size()/2<<'\n';
    for(auto x : ans) {
        cout<<x.uu<<" "<<x.vv<<'\n';
    }
    
    return 0;
}

/*

7
a
a
a
a
a
e
e
*/