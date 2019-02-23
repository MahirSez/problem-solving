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
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int  n, m;
string str[2000];
vector<int>sml[2000] , eql[2000] , bg[2000];
int A[2000] , B[2000];
int ara[2000];

bool comp(int x , int y) {

    if( sml[x].size() == sml[y].size() ) 
        return bg[x].size() > bg[y].size();
    return sml[x].size( ) < sml[y].size();
}


bool check() {


    for(int i =0 ; i < n ; i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            if(str[i][j] =='<' && A[i] < B[j]) continue;
            if(str[i][j] =='>' && A[i] > B[j]) continue;
            if(str[i][j] =='=' && A[i] == B[j]) continue;
            return false;
        }
    }
    return true;
}

int main()
{
    fastRead;
    cin>>n>>m;
    for(int i =0 ; i < n ; i++ ) {
        cin>>str[i];
    }
    for(int i =0 ; i< n ; i++ ) ara[i] = i;

    for(int i = 0 ; i < n ; i++ ) {
        for(int j =0 ; j < m ; j++ ) {
            if( str[i][j] == '>') sml[i].push_back(j);
            if( str[i][j] == '=') eql[i].push_back(j);
            if( str[i][j] == '<') bg[i].push_back(j);
        }
    }

    sort(ara , ara + n, comp);

    // for(int i =0 ; i < n ; i++ ) {
    //     cout<<ara[i]<<" ";
    // }
    // cout<<endl;
    int val = 0;

    for(int i= 0 ; i < n ; i++ ) {
    
        int id1 = ara[i];

        if( i ==0 ) {
            if(sml[id1].size()) val++;
        }
        else {
            if( sml[id1].size() > sml[ara[i-1]].size()  ) val++;
            else if( eql[id1].size() != eql[ara[i-1]].size() ) val++;
        }

        bool ok = false;

        for(int j = 0 ; j < (int)sml[id1].size() ; j++ ) {
            int id2 = sml[id1][j];
            if(B[id2] == 0 ) B[id2]= val , ok = true;
        }

        if( i ==0 || ok) 
            val++;

        A[id1] = val;

        for(int j = 0 ; j < (int)eql[id1].size() ; j++ ) {
            int id2 = eql[id1][j];
            if( B[id2] ==0 ) B[id2] = val;
        }
    }
    ++val;
    for(int i =0 ; i < m ; i++ ) {
        if(B[i] ==0 ) B[i] = val;
    }

    bool ok = check();
    // ok= true;

    if( ok ) {
        cout<<"Yes"<<endl;
        for(int i =  0 ; i < n ; i++ ) cout<<A[i]<<" ";
        cout<<endl;
        for(int i =  0 ; i < m ; i++ ) cout<<B[i]<<" ";
        cout<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
    
    return 0;
    
}