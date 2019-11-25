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

int tgt  , q , n;
int val1  , val2 ;

int solve(int id , int val ) {
    
    if(id == q) return (val == val2 );
    
    return solve(id+1 , val+1) + solve(id+1 , val-1);
}


int main()
{
    fastRead;
    string s1 , s2;
    cin>>s1>>s2;
    n = s1.size();

    for(auto x : s1) {
        if(x == '+') val1++;
        else val1--;
    }
    
    for(auto x : s2 ) {
        if(x == '+') val2++;
        else if(x == '-') val2--;
        else q++;
    }
    
    
    int up = solve(0 , val1 );
    double down = (1<<q);
    
    cout<<setprecision(12)<<fixed<<(1.0*up/down)<<'\n';
    
    return 0;
    
    
    
}