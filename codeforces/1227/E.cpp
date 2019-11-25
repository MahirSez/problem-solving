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

const int MAX = 1e6 + 6;
int n , m;

vector<vector<int> > ara , lvl;
queue<pii>q1;

int dx[] = { 0 , 0 , 1 , 1, 1 , -1 , -1 , -1 };
int dy[] = { 1 , -1 , 0 , -1 ,1  , 0 , -1 , 1};

bool isBorder(int x , int y) {
    if(ara[x][y] == 0) return 0;
    
    if(x == n-1 || x == 0 || y == m-1 || y == 0 ) return 1;
    
    for(int i =0 ; i < 8 ; i++ ) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        
        if(ara[tx][ty] == 0) return 1;
    }
    return 0;
}



void bfs1() {

    
    while(!q1.empty()) {
        
        int tx = q1.front().uu;
        int ty = q1.front().vv;
        
        q1.pop();
        
        for(int i =0 ; i < 8 ; i++ ) {
            int xx = tx + dx[i];
            int yy = ty + dy[i];
            
            if(xx >= 0 & xx < n && yy >=0 && yy < m && lvl[xx][yy] == -1 && ara[xx][yy] )  {
                lvl[xx][yy] = lvl[tx][ty] + 1;
                q1.push({xx,yy});
            }
        }
    }
    
//    for(int i =0 ; i < n ; i++ ) {
//        for(int j =0 ; j <m ; j++ ) {
//            cout<<lvl[i][j]<<"\t";
//        }
//        cout<<'\n';
//    }
}


void print(vector< vector<int> > &v)  {
    
    for(int i = 0 ; i < n ; i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            cout<<v[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}


bool ok(int lev) {

    
    queue<pii>q2;
    
    vector<vector<int> > tmpvec( n , vector<int> (m, -1)); 
    
    for(int i =0 ; i < n ; i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            
            if(ara[i][j] && lvl[i][j] >= lev) {
                tmpvec[i][j] = 0;
                q2.push({i,j});
            }
        }
    }
    
//    cout<<lev<<'\n';
//    print(tmpvec);
    
    
    while(!q2.empty()) {
        
        int tx = q2.front().uu;
        int ty = q2.front().vv;
        q2.pop();
        
        if(tmpvec[tx][ty] == lev) continue;
        
        for(int i =0 ; i < 8 ; i++ ) {
            int xx = tx + dx[i];
            int yy = ty + dy[i];
    
            
            if(xx >= 0 & xx < n && yy >=0 && yy < m && tmpvec[xx][yy] == -1  )  {
                tmpvec[xx][yy] = tmpvec[tx][ty] + 1;
                q2.push({xx,yy});
            }
        }
    }
    
//    print(tmpvec);
//    cout<<"=== \n";
    
    for(int i =0 ; i < n ; i++) {
        for(int j =0 ; j < m ;j++ ) {
            if( tmpvec[i][j] != -1&& ara[i][j] ==0 ) return 0;
            if( tmpvec[i][j] == -1 && ara[i][j] ) return 0;
        }
    }
    return 1;
}


int solve() {


    int lo = 0 , hi = 1e6 , ans = -1;
    while(lo<= hi) {
        
        int mid = (lo+hi)/2;
        
        if(ok(mid)) {
            lo = mid + 1;
            ans = mid;
        }
        else hi = mid-1;
    }
    
    return ans;
}


int main()
{
    fastRead;
    cin>>n>>m;
    
    for(int i =0 ; i< n ; i++ ) {
        string str;
        cin>>str;
        vector<int>vec , tmp;
        for(auto x : str) {
            if(x == 'X') vec.push_back(1);
            else vec.push_back(0);
            tmp.push_back(-1);
        }
        ara.push_back(vec);
        lvl.push_back(tmp);
    }
    
    
    for(int i =0 ; i< n; i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            if(isBorder(i , j ) ) {
                lvl[i][j] = 0;
                q1.push({i,j});
            }
        }
    }
    
    bfs1();
    
    int ans = solve();
    
    cout<<ans<<'\n';
    
    for(int i =0 ; i < n; i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            
            if(lvl[i][j] >= ans )  cout<<"X";
            else cout<<".";
        }
        cout<<'\n';
    }
    
    return 0;
}