#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS		1e-8
#define MAX		1000006
using namespace std;
vector<string>v;
vector<string>mem[10000];
int n , tmp  ,  ans;
map<string , int>mp;
string str,str1;
int cnt, t;

map<string, bool>rec;


int solve(string par ,string child) {


    if( par== child) return 0;

    reverse(par.begin() , par.end());
    reverse(child.begin() , child.end());

    if( par.size() > child.size()) {

        for( int i = 0; i <child.size() ; i++ ) {

            if( child[i] != par[i] ) return 0;
        }
        return 2;
    }
    else {

        for( int i = 0; i < par.size() ; i++ ) {

            if( child[i] != par[i] ) return 0;
        }
        return 1;
    }
}

void process(int id) {

    rec.clear();
    for( int  i =0 ;i< mem[id].size() ; i++) {

        string par = mem[id][i];

        if( rec[par] == true) continue;

        for( int j = 0; j < mem[id].size(); j++) {

            if( i == j ) continue;
            string child = mem[id][j];

            if( rec[child] == true) continue;
//            cout<<par<<" "<<child<<endl;
            int tmp = solve(par, child);
            if( tmp == 1 ) rec[par] = true;
            else if( tmp == 2) rec[child] = true;

        }

    }

    vector<string>ans;
    for( int  i =0 ; i < mem[id].size(); i++ ) {

        string str = mem[id][i];

        if( rec[str] == false) {
            rec[str] = true;
            ans.push_back(str);
        }
    }
    cout<<ans.size()<<" ";
    for( int  i =0 ; i < ans.size() ; i++)
        cout<<ans[i]<<" ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    for( int  i =0 ; i < t ; i++) {

        cin>>str;
        if( mp[str] == 0) {
            mp[str] = ++cnt;
            v.push_back(str);

        }
        int tmp = mp[str];

        cin>>n;

        for( int j = 0; j < n ; j ++) {
            cin>>str1;
            mem[tmp].push_back(str1);
        }
    }

//    cout<<v.size()<<endl;
    cout<<v.size()<<endl;
    for( int  i =0 ; i < v.size(); i++) {

        int id = mp[ v[i] ];
//        cout<<mem[id].size()<<endl;

        cout<<v[i]<<" ";
        process(id);
        cout<<endl;
    }
    return 0;

}
