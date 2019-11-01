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
const int MAX_V=1e6 +6;
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

vector<int>prm ;
const int MAX = 1e6 + 6;
int mark[MAX] , ara[200];

void seive() {

    for(int i =2 ; i *i < MAX ; i++ ) {
        if(mark[i]) continue;
        for(int j = i *i ; j < MAX ; j+=i) mark[j] = 1;
    }
    
    for(int i =2 ;i < MAX  ;i++ ) {
        if(mark[i] == 0 ) prm.push_back(i);
    }
//    long long ret = 1 , cnt = 0;
//    for(int i = 0 ; ret *prm[i] < 1e9 ; i++ ) {
//        ret *=prm[i];
//        cnt++;
//    }
//    cout<<cnt<<'\n';
}

map<int,int>frm[200] ,to[200];
int node ;

void factorize(int num , int id) {
    
    for(int i = 0 ; i < prm.size() && num > 1; i++ ) {
        
        if(num%prm[i] ) continue;
        int cnt = 0;
        while(num%prm[i] == 0) {
            num /=prm[i];
            cnt++;
        }
        
        frm[id][prm[i]] = ++node;
        to[id][prm[i]] = ++node;
        
        addedge(frm[id][prm[i]] , to[id][prm[i]] , cnt , 0);
        if(id&1) addedge(S , frm[id][prm[i]] , INF ,0);
        else addedge(to[id][prm[i]] , T , INF , 0);
    }
    if(num > 1) {
        
        frm[id][num] = ++node;
        to[id][num] = ++node;
        
        addedge(frm[id][num] , to[id][num] , 1 , 0);
        if(id&1) addedge(S , frm[id][num] , INF ,0);
        else addedge(to[id][num] , T , INF , 0);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    seive();
    reset();
    S = 0 , T = MAX_V -1;
    
    
    int n , m;
    cin>>n>>m;
    for(int i =1 ; i<=n ; i++ ) {
        cin>>ara[i];
        factorize(ara[i] , i );
    }
    
    while(m--) {
        
        int id1 , id2;
        cin>>id1>>id2;
        if(id2&1) swap(id1 , id2);
        
        int gcd = __gcd(ara[id1] , ara[id2]);
        
        for(int i =0 ; i < prm.size() && gcd > 1; i++) {
            
            if(gcd%prm[i]) continue;
            addedge(to[id1][prm[i]] , frm[id2][prm[i]] , INF , 0);
            while(gcd%prm[i]==0) gcd/=prm[i];
        }
        
        if(gcd > 1) {
            
            addedge(to[id1][gcd] , frm[id2][gcd] , INF ,0);
        }
    }
    cout<<flow()<<'\n';
    return 0;
}
