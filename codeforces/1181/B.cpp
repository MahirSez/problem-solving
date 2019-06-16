#include <bits/stdc++.h>
#define ll          long long int
#define PI          acos(-1)
#define read        freopen("input.txt","r",stdin)
#define uu          first
#define vv          second
#define write       freopen("output.txt","w",stdout)
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define EPS         1e-8
#define MAX         1000006
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
string str1 , str2 , str , ans , cand;


bool small() {

    if( cand.size() < ans.size() ) return true;
    
    if( ans.size() < cand.size()) return false;
    
    for(int i =0 ; i < cand.size() ; i++ ) {
        
    
        if( ans[i] == cand[i]) continue;
        if( cand[i] < ans[i]) return true;
        
        return false;
    }
    return false;
}


void process() {

    
    reverse(str1.begin() , str1.end() );
    reverse(str2.begin() , str2.end() );
    while( str1.size() < str2.size() ) str1 +='0';
    while( str2.size() < str1.size() ) str2 +='0';
    
    int n = str1.size() , carry = 0;
    cand = "";
//    cout<<str1<<" "<<str2<<endl;
    
    for(int i =0 ; i < n ; i++ ) {
        
        
        int id1 = str1[i] -'0';
        int id2 = str2[i] -'0';
        int sum = id1 + id2 + carry;
        
        carry = (sum/10);
        
        sum%=10;
        
        cand += char(sum + '0');
    }

    
    if( carry) cand += char(carry + '0');
    reverse(cand.begin() , cand.end() );
    
    
    
    if( small() ) ans = cand;
    
}


int main()
{
    
    fastRead;
    int n;
    cin>>n>>str;
    
    ans = "";
    
    for(int i =0 ; i < n +10; i++ ) ans += '9';
    
    vector<int>pos;
    
    for(int i= 0 ; i < str.size() ; i++ ) {
        if( str[i] != '0') pos.push_back(i);
    }
    int nn = pos.size();
    int tmp = n/2;
    tmp = lower_bound(pos.begin() , pos.end() , tmp) - pos.begin();
    
    int frm = max(tmp-10 , 0);
    int to = min(tmp+10 , nn-1);
    
    
    for(int i = frm ; i <=to ; i++ ) {
        
        int id = pos[i];
        
        if( id == 0 || str[id] == '0') continue;
        
        str1 = "";
        str2 = "";
        for(int j = 0 ; j < id  ; j++ ) str1 += str[j];
        for(int j = id ; j < n ; j++) str2 += str[j];
        
        
//        cout<<str1<<" "<<str2<<endl;
        process();

    }
    cout<<ans<<'\n';
    
    return 0;
}