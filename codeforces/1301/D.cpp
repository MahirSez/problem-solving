#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

int n , m , k;

vector<int>rec1;
vector<string>rec2;

void print() {
    
    vector<int>ans1;
    vector<string>ans2;
    
    for(int i = 0 ; i < rec1.size() ; i++ ) {
        
        if(rec1[i] == 0 ) continue;
        ans1.push_back(rec1[i]);
        ans2.push_back(rec2[i]);
    }
    
    
    cout<<ans1.size()<<'\n';
    for(int i =0 ; i < ans1.size() ; i++ ) cout<<ans1[i]<<" "<<ans2[i]<<'\n';
    exit(0);
}

int main()
{
    fastRead;
    cin>>n>>m>>k;
    
    int mx = 4*n*m - 2*n - 2*m;
    
    if(k > mx) {
        cout<<"NO\n";
        return 0;
    }
    
    cout<<"YES\n";
    
    rec1.push_back(min(m-1 , k) );
    rec2.push_back("R");
    
    k -=m-1;
    if(k <= 0 ) print();
    
    for(int i =0 ; i < m-1 ; i++ ) {
        
        rec1.push_back( min(n -1, k ));
        rec2.push_back("D");
        k -= n-1;
        if(k <= 0) print();
        
        rec1.push_back( min(n-1 , k ));
        rec2.push_back("U");
        k -= n-1;
        if(k <= 0) print();
        
        
        rec1.push_back(1);
        rec2.push_back("L");
        k--;
        if(k <= 0) print();
    }
    
    
    rec1.push_back(min(n-1 , k));
    rec2.push_back("D");
    
    k -= n-1;
    if(k <= 0 ) print();
    
    
    for(int i =0 ; i <n-1; i++ ) {
        
        rec1.push_back( min(m-1 , k));
        rec2.push_back("R");
        k -= m-1;
        if(k <= 0) print();
        
        rec1.push_back( min(m-1 , k));
        rec2.push_back("L");
        k -= m-1;
        if(k <= 0) print();   
        
        rec1.push_back(1);
        rec2.push_back("U");
        k--;
        if(k <=0) print();
        
    }
    
    assert(k == 0 );
    
    return 0;
    
}