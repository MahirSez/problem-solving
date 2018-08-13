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
int n , taken[MAX] , cst[MAX];
vector<pair<int,string> >v;
vector<int>id;
int main()
{
    fastRead;
    cin>>n;
    for(int i=0 ; i < n ; i++ ) {
        string tmp;
        int a;
        cin>>tmp>>a;
        v.push_back({a,tmp});
    }
    sort( v.begin() , v.end() ) ;

    int now = 0;
    for(int i =0 ;i < v.size() ; i++ ) {

        int val = v[i].uu;
        string name = v[i].vv;
//        cout<<endl<<endl<<"------>"<<val<<" "<<name<<endl;

        if( val > i ) {
            cout<<-1<<endl;
            return 0;
        }

        if( val != now) {

            int diff = val - now ;
            for(int j = i- 1 ;  j>=0 && diff>0 ; j-- ) {
                if( taken[j] == 0 ) {
                    diff--;
                    taken[j] = 1;

                    id.push_back(j);
                }
            }
            now = val;
        }
        for(int j =0 ; j < id.size() ; j++ )  {
            cst[id[j]]++;
        }

        while( i < v.size() && val == v[i].uu) {
            i++;
        }
        i--;

        id.push_back(i);
        taken[i] = 1;
        now++;

    }
//    for(int i =0 ; i < id.size() ; i++ ) {
//        cout<<id[i]<<" ";
//    }
//    cout<<endl;

    for(int i = 0 ; i < n ; i++ ) {
        cout<<v[i].vv<<" "<<1 + cst[i]<<endl;
    }
    return 0;
}
