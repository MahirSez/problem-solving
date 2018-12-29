#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll         pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n , len;

vector<string>rcd;
map<string,int>mp;
vector<ll>edg[MAX];



int main()
{
    fastRead;
    cin>>n>>len;
    for(int i =0 ; i < n ; i++ ){
        string str;
        ll val;
        cin>>str>>val;
        if( mp.count(str)==0) {
            mp[str] = rcd.size();
            rcd.push_back(str);
        }
        edg[mp[str]].push_back(val);
    }


    for(int i =0 ; i < rcd.size() ; i++) {
        sort(edg[i].begin() , edg[i].end());
    }


    ll beauty = 0;
    ll center = 0;
    for(int i =0 ; i < rcd.size() ; i++ ) {

        string str = rcd[i];
//        cout<<" --- "<<i<<" "<<mp[str]<<endl;
        string rev = str;
        reverse(rev.begin() , rev.end());

        if( str == rev) {

            int id = mp[str];

            for(int j = edg[id].size()-2 ; j >=0 ; j-=2 ) {

                ll tmp = edg[id][j] + edg[id][j+1] ;
                if( tmp <= 0) {

                    center = max(center , edg[id][j+1]);
                    break;
                }
                else {
                    center = max(center , -edg[id][j]);

                    beauty += tmp;

                    edg[id].erase(edg[id].begin() + j , edg[id].end());
                }
            }

            if( (int)edg[id].size() >0 ) center = max(center , edg[id][0]);
        }
        else {
            if( mp.count(rev) == 0) continue;

            int id1 = mp[str];
            int id2 = mp[rev];

            for(int j = edg[id1].size()-1 , k = edg[id2].size()-1 ; j>=0 && k>=0 ; k--, j--) {

                ll tmp = edg[id1][j] +edg[id2][k];
                if( tmp <= 0) break;

                beauty += tmp;
                edg[id1].erase(edg[id1].begin() + j , edg[id1].end());
                edg[id2].erase(edg[id2].begin() + k , edg[id2].end());
            }
        }
    }

    cout<<beauty + center<<endl;
    return 0;
}
