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
string str;
int n ;
vector<string>v;

int subStr(string sml , string bg) {
//    cout<<sml<<" "<<bg<<endl;
    int sz = sml.size();
    for(int i =0 ; i + sz -1< bg.size() ; i++ ) {
        string tmp = "";
        for(int j = i , cnt = 0; cnt < sz ; j++ ,cnt++ ) {
            tmp += bg[j];
        }
        if( tmp ==sml) return 0;
    }
    return -1;
}

int main()
{
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        cin>>str;
        v.push_back(str);
    }
    for(int i =0 ; i < n ; i++) {
        for(int j = i+1 ; j < n ;j++  ) {
            string tmp1 = v[i];
            string tmp2 = v[j];
            int ok = subStr(tmp1 , tmp2);
            int okk = subStr(tmp2 , tmp1);
//            cout<<tmp1<<" "<<tmp2<<" "<<ok<<" "<<okk<<endl;
            if( ok  == -1 && okk==-1) {
                cout<<"NO"<<endl;
                return 0;
            }
            else if( okk== 0 ) {
                swap(v[i],v[j]);
            }
        }
    }
    cout<<"YES"<<endl;
    for(int  i= 0 ; i < n ; i++ ) {
        cout<<v[i]<<endl;
    }
    return 0;
}
