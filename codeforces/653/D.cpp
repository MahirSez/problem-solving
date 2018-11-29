// Noor vai's Dinic Kode
// O(|E|*|V|^2)
#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000
#define EPS 1e-12

const int MAX_E=60003;
const int MAX_V=5003;
int ver[MAX_E],cap[MAX_E],nx[MAX_E],last[MAX_V],ds[MAX_V],st[MAX_V],now[MAX_V],edge_count,S,T;

void reset()
{
	memset(nx,-1,sizeof(nx));
	memset(last,-1,sizeof(last));
	edge_count=0;
}
void addedge(const int v,const int w,const int capacity,const int reverse_capacity)
{
	ver[edge_count]=w; cap[edge_count]=capacity; nx[edge_count]=last[v]; last[v]=edge_count++;
	ver[edge_count]=v; cap[edge_count]=reverse_capacity; nx[edge_count]=last[w]; last[w]=edge_count++;
}
bool bfs()
{
	memset(ds,-1,sizeof(ds));
	int a,b;
	a=b=0;
	st[0]=T;
	ds[T]=0;
	while (a<=b)
	{
		int v=st[a++];
		for (int w=last[v];w>=0;w=nx[w])
		{
			if (cap[w^1]>0 && ds[ver[w]]==-1)
			{
				st[++b]=ver[w];
				ds[ver[w]]=ds[v]+1;
			}
		}
	}
	return ds[S]>=0;
}
int dfs(int v,int cur)
{
	if (v==T) return cur;
	for (int &w=now[v];w>=0;w=nx[w])
	{
		if (cap[w]>0 && ds[ver[w]]==ds[v]-1)
		{
			int d=dfs(ver[w],min(cur,cap[w]));
			if (d)
			{
				cap[w]-=d;
				cap[w^1]+=d;
				return d;
			}
		}
	}
	return 0;
}
long long flow()
{
	long long res=0;
	while (bfs())
	{
		for (int i=0;i<MAX_V;i++) now[i]=last[i];
		while (1)
		{
			int tf=dfs(S,INF);
			res+=tf;
			if (!tf) break;
		}
	}
	return res;
}

int n , m , x;
vector<pair<int,double> >edg[MAX_E];

bool ok(double val) {

    reset();
    for(int i =1 ; i <=n ; i++ ) {
        for(int j =0 ; j < edg[i].size() ; j++ ) {

            addedge( i, edg[i][j].first , floor(edg[i][j].second/val), 0);
        }
    }
    double ans = flow();
//    cout<<val<<" "<<ans<<" "<<(ans >= x)<<endl;
    return ans >= x;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>x;
    S = 1;
    T = n;
    while( m-- ) {
        int u , v ;
        double w;
        cin>>u>>v>>w;
        edg[u].push_back({v ,w});
    }

    double lo = 1 , hi = 1e8 ,mid;
    for(int i = 0 ; i < 200 ; i++) {

        mid = (lo+hi)/2.00;
        if( ok(mid/x) ) {
            lo = mid;
        }
        else hi = mid;
    }
    cout<<setprecision(12)<<fixed<<lo<<endl;
    return 0;
}
