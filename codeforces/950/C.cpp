#include <bits/stdc++.h>
#define ll      long long int
#define PI      acos(-1)
#define read    freopen("in.txt","r",stdin)
#define uu      first
#define vv      second
#define write   freopen("out.txt","w",stdout)
#define pii     pair<int,int>
#define INF     1e9
#define EPS     1e-8
#define MAX     1000006
#define MOD     1000000007
using namespace std;
string str;
vector<int>init;
queue<int>one;
queue<int>zero;
int pos[MAX];
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>str;
    bool flg = true;
    for(int  i= 0 ; i < str.size(); i++ ) {

        if( str[i] == '0' && one.empty() ) {
            init.push_back(i);
            zero.push(i);
        }

        else if( str[i] == '1' ) {

            if( zero.empty()) {
                flg = false;
                cout<<"-1"<<endl;
                return 0;
            }

            else {

                int id = zero.front();
                zero.pop();
                pos[id] = i;
                one.push(i);
            }
        }
        else {

            int id = one.front();
            one.pop();
            pos[id] = i;
            zero.push(i);
        }
    }


    if( !one.empty() ) {
        cout<<"-1"<<endl;
        return 0;
    }


    cout<<init.size()<<endl;
    for(int  i=0 ; i < init.size() ;i++) {

        vector<int>tmp;
        int id = init[i];
        while(true) {

            tmp.push_back(id);
            if( pos[id] == 0) break;
            id = pos[id];
        }

        cout<<tmp.size();
        for(int  i =0 ; i < tmp.size() ;i++)
            cout<<" "<<tmp[i]+1;
        cout<<endl;
    }
    return 0;
}
