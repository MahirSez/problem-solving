// Dinic's Max Flow
// Complexity->  O(|E|*|V|^2) , but much faster
#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000


// INPUT:
//     - At first , Call reset();    
//     - graph, constructed using addEdge()
//     - S = source and T = sink
//
// OUTPUT:
//     - maximum flow value
//     - To obtain flow values of each edge, (Original_cap[edge_i] - Obtained_cap[edge_i] )
//       (zero capacity edges are residual edges).
//
// change the value of MAX_E & MAX_V as needed
//


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
//    cout<<v<<" "<<w<<" "<<capacity<<'\n';
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


const int MAX = 1e6 + 6;
int mark[MAX] ;

void seive() {

    for(int i =2 ; i *i < MAX ; i++ ) {
        if(mark[i]) continue;
        for(int j = i *i ; j < MAX ; j+=i) mark[j] = 1;
    }
}
int n , k , p[200] , c[200] ;
vector<int>rec[200];

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    seive();
    cin>>n>>k;
    for(int i =1 ; i <= n ; i ++) {
        cin>>p[i]>>c[i];
        int lvl;
        cin>>lvl;
        rec[lvl].push_back(i);
    }
    
    int lo = 1 , hi = n , ans = -1;
    
    S = 0 , T = MAX_V-1;
    
    
    while(lo<=hi) {
        
        int mid = (lo+hi)/2;
//        cout<<lo<<" "<<hi<<" lvl = "<<mid<<'\n';
        reset();
        
        
        vector<int>odd , ev , one;
        int tot = 0;
        
        
        for(int i =1 ; i <=mid ; i++ ) {
            
            for(auto x : rec[i]) {
                if(c[x]&1) {
                        
                    if(c[x] == 1) one.push_back(x);
                    else {
                        odd.push_back(x);
                        addedge(S , x , p[x] , 0);
                    }
                }
                else {
                    ev.push_back(x);
                    addedge(x , T , p[x] , 0);
                }
                if(c[x] != 1 )tot += p[x];
            }
        }
        
        int oneid = -1 ;
        for(auto x : one) {
            if(oneid == -1 || p[x] > p[oneid]) oneid = x;
        }
        
        if(oneid != -1) {
            addedge(S , oneid , p[oneid] , 0);
            odd.push_back(oneid);
            tot += p[oneid];
        }
        
        
        
        for(auto x : odd) {
            for(auto y : ev) {
                
                if(mark[c[x] + c[y]] == 0 ) addedge(x , y , INF , 0);
            }
        }
        
//        cout<<"before"<<'\n';
        int ret = flow();
//        cout<<"flow = "<<ret<<'\n';
        
        tot -= ret;
//        cout<<"tot = "<<tot<<'\n';
        if(tot >= k) {
            ans = mid;
            hi = mid-1;
        }
        else lo = mid+1;
        
//        cout<<'\n';
        
    }
    cout<<ans<<'\n';
    return 0;
}
