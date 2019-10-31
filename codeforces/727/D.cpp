// Dinic's Max Flow
// Complexity->  O(|E|*|V|^2) , but much faster
#include<bits/stdc++.h>
using namespace std;
#define INF 2000000000
#define pii pair<int,int>
#define uu first
#define vv second


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


const int MAX_E=1e6+6;
const int MAX_V=1e6+6;
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
int ara[10] ;
string sara[10];
map<string ,int>mp;
vector<pii>vec[MAX_V];
int n;
int main()
{
    mp["S"] = 1;
    mp["M"] = 2;
    mp["L"] = 3;
    mp["XL"] = 4;
    mp["XXL"] = 5;
    mp["XXXL"] = 6;
    for(int i =1 ; i<=6 ; i++ ) cin>>ara[i];
    sara[1] = "S";
    sara[2] = "M";
    sara[3] = "L";
    sara[4] = "XL";
    sara[5] = "XXL";
    sara[6] = "XXXL";
    
    reset();
    
    S = 0;
    T = MAX_V -1;
    
    for(int i =1 ; i<=6 ; i++ ) addedge(S , i , ara[i] , 0) ;
    cin>>n;
    for(int i = 101 ; i<= n + 100 ; i++ ) {
        
        string str;
        cin>>str;
        
        string s1 = "" , s2 = "";
        
        bool flg = false;
        for(auto x : str) {
            if(x==',') {
                flg = 1;
                continue;
            }
            
            if(!flg) s1 += x;
            else s2 += x;
        }
        vec[i].push_back({edge_count , mp[s1]});
        addedge(mp[s1] , i , 1 , 0);
        
        if(s2 != "") {
            vec[i].push_back({edge_count , mp[s2]});
            addedge(mp[s2] , i , 1 , 0);
        }
        
        addedge(i , T , 1 , 0);
    }
    
    int ret = flow();
    if(ret != n) {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(int i =101 ; i<=n +100; i++ ) {
        
        for(auto x : vec[i]) if(cap[x.uu] == 0) cout<<sara[x.vv]<<'\n';
    }
    return 0;
}
