#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int d , s , vis[600][6000];

string bfs() {

    queue<pair< pii , string> > q;
    q.push({ {0 , 0} , ""});
    while( !q.empty() ) {

        int rem = q.front().uu.uu;
        int sum = q.front().uu.vv;
        string now = q.front().vv;
        if( now.size() && rem == 0 && sum == s) return now;
        q.pop();

        for(int i =0 ; i < 10 ; i++ ) {
            if( i==0 && now.size() ==0 ) continue;
            int newRem = (rem*10 + i) % d;
            if(sum + i <= s && vis[newRem][sum+i] ==0 ) {
                vis[newRem][sum+i] = 1;
                q.push({{newRem , sum+i} , now + (char)('0' + i)});
            }
        }
    }
    return "-1";
}

int main()
{
    cin>>d>>s;
    cout<<bfs()<<endl;
    return 0;
}
