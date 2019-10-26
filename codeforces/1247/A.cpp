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
int n , ara[MAX];

int main()
{
    fastRead;
    
    
    int a , b;
    cin>>a>>b;
    if(a +1== b)cout<<a<<" "<<b<<'\n';
    else if(a == 9 && b == 1) cout<<9<<" "<<10<<'\n';
    else if(a == b) cout<<a<<0<<" "<<b<<1<<'\n';
    else cout<<-1<<'\n';
    return 0;
}