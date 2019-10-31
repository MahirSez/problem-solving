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
int n , t ;
int src[20][20] , dest[20][20] , node[20][20] , ndcnt , gasvis[20][20] , vis[20][20];
int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , -1 , 1};

void bfs1() {

    int fx = -1 , fy = -1;
    for(int i =0 ; i < n ; i++) {
        for(int j =0 ; j < n ; j++ ) {
            if(src[i][j] == -2) {
                fx = i;
                fy = j;
            }
            gasvis[i][j] = INF;
        }
        
        
    }
    
    
    queue<pii>q;
    q.push({fx , fy});
    gasvis[fx][fy] = 0;
    
    while(!q.empty()) {
        
        int x = q.front().uu;
        int y = q.front().vv;
        q.pop();
        
        for(int i =0 ; i < 4 ; i++ ) {
            
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(xx>=0 && yy>=0 && xx < n && yy < n && src[xx][yy] >= 0 && gasvis[xx][yy] > gasvis[x][y] + 1 ) {
                
                gasvis[xx][yy] = gasvis[x][y] + 1;
                q.push({xx ,yy});
            }
        }
    }
    
//    for(int i =0 ; i < n ; i++ ) {
//            for(int j =0 ; j < n ; j++) {
//                if(gasvis[i][j] == INF) gasvis[i][j] = -1;
//            }
//    }
    
//    for(int  i =0 ; i < n ; i++ ) {
//        for(int j =0 ; j < n ; j++ ) {
//            cout<<gasvis[i][j]<<" ";
//        }
//        cout<<'\n';
//    }
}

void bfs2(int fx , int fy) {

    for(int i =0 ; i< n ; i++ ) {
        for(int j =0 ;j < n ; j++ ) vis[i][j] = INF;
    }
    
    
//    cout<<" "<<fx<<" "<<fy<<'\n';
    queue<pii>q;
    q.push({fx , fy});
    vis[fx][fy] = 0;
    
    while(!q.empty()) {
        
        int x = q.front().uu;
        int y = q.front().vv;
        
        q.pop();
        
        if(vis[x][y] > gasvis[x][y]) continue;
        if(dest[x][y] > 0 ) addedge(node[fx][fy] , node[x][y] + 1000 , INF , 0);
        if(vis[x][y] == gasvis[x][y]) continue;
        
        if(vis[x][y] == t) continue;
        
        for(int i =0 ; i < 4 ; i++ ) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if(xx>=0 && yy>=0 && xx < n && yy < n && src[xx][yy] >= 0 && vis[xx][yy] > vis[x][y] + 1 ) {
                vis[xx][yy] = vis[x][y] + 1;
                q.push({xx ,yy});
            }
        }
    }
    
//    for(int i =0 ; i <n ; i++ ) {
//        
//        for(int j = 0 ; j < n ; j++ ) {
//            
////            cout<<vis[i][j]<<" ";
//            
//            if(dest[i][j] <=0) continue;
//            if(vis[i][j] == INF)continue;
//            if(vis[i][j] > gasvis[i][j]) continue;
//            if(vis[i][j] > t) continue;
//            
//            addedge(node[fx][fy] , node[i][j] + 1000 , INF ,0);
//        }
////        cout<<'\n';
//    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t;
    reset();
    
    S= 0 , T = MAX_V -1;
    
    for(int i =0 ; i < n; i++ ) {
        for(int j =0 ; j < n ; j++ ) node[i][j] = ++ndcnt;
    }
    
    for(int i =0 ; i < n ; i++ ) {
        
        string str;
        cin>>str;
        for(int j =0 ; j <n ; j++ ) {
            if(str[j] == 'Y')src[i][j] = -1;
            else if(str[j] == 'Z') src[i][j] = -2;
            else src[i][j] = (str[j] -'0');
        }
    }
//    cout<<"here"<<'\n';
    
    for(int i =0 ; i < n ; i++ ) {
        
        string str;
        cin>>str;
        for(int j =0 ; j <n ; j++ ) {
            if(str[j] == 'Y')dest[i][j] = -1;
            else if(str[j] == 'Z') dest[i][j] = -2;
            else dest[i][j] = (str[j] -'0');
        }
    }    
    
    bfs1();
    
    for(int i = 0 ; i < n ; i++ ) {
        for(int j =0 ; j < n ; j++ ) {
            
            if(src[i][j] > 0) addedge(S , node[i][j] , src[i][j] , 0);
            if(dest[i][j] > 0 ) addedge(node[i][j]+ 1000 , T , dest[i][j] , 0);
        }
    }
    
    
    for(int i =0 ; i < n ; i++ ) {
        for(int j = 0; j < n ; j++ ) {
            
            if(src[i][j] <=0 ) continue;
            bfs2(i , j);
        }
    }
    
    cout<<flow()<<'\n';
    
    
    return 0;
}
