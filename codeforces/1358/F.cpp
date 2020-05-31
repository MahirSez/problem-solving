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

void solve1(vector<ll>&a , vector<ll>&b) {
    if(a[0] == b[0]) {
        cout<<"SMALL\n";
        cout<<0<<'\n';
    }
    else {
        cout<<"IMPOSSIBLE\n";
    }
    exit(0);
}


void printSolution(int op1, int op2, string s) {
    if(op2 > 2e5) {
        cout<<"BIG\n";
        cout<<op2<<'\n';
    }
    else {
        cout<<"SMALL\n";
        cout<<op1 + op2<<'\n';
        reverse(s.begin(), s.end());
        cout<<s<<'\n';
    }
}

bool same(vector<ll>&a , vector<ll>&b, int flg) {
    
    if(flg) reverse(b.begin() , b.end());
    bool ok = 1;
    for(int i =0 ; i < a.size() ; i++) {
        if(a[i] != b[i]) ok = 0;
    }
    if(flg) reverse(b.begin() , b.end());
    return ok;
}


bool decreasing(vector<ll>&vec) {
    
    for(int i =1 ; i < vec.size() ; i++ ) {
        if(vec[i] >= vec[i-1]) return 0;
    }
    return 1;
}

bool increasing(vector<ll>&vec) {
    
    for(int i =1 ; i < vec.size() ; i++ ) {
        if(vec[i] <= vec[i-1]) return 0;
    }
    return 1;
}
/*
4
1 1 1 1
20 50 84 119
*/

void solve3(vector<ll>&a, vector<ll>&b) {
    
    string ans = "";
    int op2 = 0 , op1 = 0;
    
    while(1) {
    
        if(same(a,b, 0)) {
            printSolution(op1 , op2 , ans);
            exit(0);
        }
        if(same(a,b,1)) {
            ans += 'R';
            op1++;
            printSolution(op1 , op2 , ans);
            exit(0);
        }
        
        if(decreasing(b)) {
            reverse(b.begin() , b.end());
            ans += 'R';
            op1++;
            continue;
        }
        
        if(!increasing(b)) {
            cout<<"IMPOSSIBLE\n";
            exit(0);
        }
        ans += 'P';
        op2++;
        for(int i = b.size()-1 ; i > 0 ; i--) {
            b[i] -= b[i-1];
        }
        
    }
}

void printSolution(ll op1, ll op2, vector<pll>ans,int flg = 0 ) {
    if(op2 > 2e5) {
        cout<<"BIG\n";
        cout<<op2<<'\n';
    }
    else {
        cout<<"SMALL\n";
        cout<<op1 + op2<<'\n';
        string s = "";
        for(auto x : ans) {
            if(x.uu == 1) s += 'R';
            else {
                while(x.vv--) s += 'P';
            }
        }
        reverse(s.begin() , s.end());
        if(flg) cout<<'R';
        cout<<s<<'\n';
    }
}

bool endstate(vector<ll>&a, vector<ll> &b) {
    
    if(a[0] != b[0]) return 0;
    if( b[1] < a[1]  ) return 0;
    
    return ( ( b[1] - a[1] ) % b[0] ) == 0;
    
}
/*
2
1 1
1 4
*/

void solve2(vector<ll>&a , vector<ll>&b) {

    vector<pll>ans;
    ll op1 = 0 , op2 = 0;
    int flg = 0;
    
    if(same(a, b, 0) ) {
        printSolution(op1, op2, ans);
        exit(0);
    }
    
    if(a[0] > a[1]) {
        swap(a[0] , a[1]);
        op1++;
//        ans.push_back({1,1});
        flg = 1;
    }
    
    while(b[0] > 0 && b[1] > 0) {
        
        if(endstate(a, b)) {
            
            ll tmp = (b[1] - a[1])/b[0];
            op2 += tmp;
            ans.push_back({2, tmp});
            printSolution(op1, op2, ans, flg);
            exit(0);
        }
        
        if(b[0] > b[1]) {
            swap(b[1] , b[0]);
            op1++;
            ans.push_back({1,1});
            continue;
        }
        
        ll tmp = b[1] / b[0];
        
        op2 += tmp;
        ans.push_back({2, tmp});
        b[1] %= b[0];
    }
    cout<<"IMPOSSIBLE\n";
    exit(0);
}


int main()
{
    fastRead;
    int n ;
    cin>>n;
    vector<ll>a(n) , b(n);
    for(int i =0 ; i < n ; i++ ) cin>>a[i];
    for(int i =0 ; i < n ; i++ ) cin>>b[i];
    
    if(n == 1) solve1(a , b);
    else if(n == 2) solve2(a, b);
    else solve3(a, b);
    
    return 0;
}