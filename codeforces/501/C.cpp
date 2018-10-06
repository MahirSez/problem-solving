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
int n;
int sum[MAX] , edg[MAX];
vector<pii>v;
int main()
{
    fastRead;
    cin>>n;
    queue<int>q;
    for(int i = 0 ; i < n ; i++ ) {
        cin>>edg[i]>>sum[i];
        if( edg[i] ==1 ) q.push(i);
    }
    while( !q.empty() ) {
        int top = q.front();
        q.pop();
        if( edg[top] == 0 )continue;
        v.push_back({top , sum[top] });
        int tmp = sum[top];
        edg[tmp]--;
        sum[tmp] ^= top;
        if( edg[tmp] ==1 ) q.push(tmp);
    }
    cout<<v.size()<<endl;
    for(int i =0 ; i < v.size() ; i++ ) {
        cout<<v[i].uu<<" "<<v[i].vv<<'\n';
    }
    cout<<endl;
    return 0;
}
