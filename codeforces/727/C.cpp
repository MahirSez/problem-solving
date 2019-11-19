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
int ara[MAX];

int ask(int a , int b) {
    cout<<"? "<<a<<" "<<b<<endl;
    int tmp;
    cin>>tmp;
    return tmp;
}

int main()
{
    fastRead;
    int n;
    cin>>n;
    
    int x , y , z;
    x = ask(1 , 2);
    y = ask(2 , 3);
    z = ask(3 , 1);
    
    int tot = (x + y + z)/2;
    
    ara[1] = tot - y;
    ara[2] = tot - z;
    ara[3] = tot - x;
    
    for(int i = 4 ; i <=n ; i++ ) {
        int tmp = ask(i-1 , i);
        ara[i] = tmp - ara[i-1];
    }
    
    cout<<"! ";
    for(int i =1;  i <=n ; i++ ) cout<<ara[i]<<" ";
    cout<<endl;
    
}