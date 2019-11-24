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
int n , k ;
string str;
vector<pii>vec;

void Reverse(int frm , int to) {
    
    while(frm < to) {
        swap(str[frm] , str[to]);
        frm++;
        to--;
    }
}

void findOpen(int frm) {
    
    for(int i = frm ; i < n ; i++ ) {
        if(str[i] == '(') {
            Reverse(frm , i);
            vec.push_back({frm,i});
            return;
        }
    }
    assert(0);
}
void findClose(int frm) {
    
    for(int i = frm ; i < n ; i++ ) {
        if(str[i] == ')') {
            Reverse(frm , i);
            vec.push_back({frm,i});
            return ;
        }
    }
    assert(0);
}


int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        vec.clear();
        
        cin>>n>>k>>str;
        int sing = n/2 - k + 1;
        
        for(int i =0 ; i < n ; i++ ) {
            
            if(i < 2*(k - 1) )  {
                if(i&1) findClose(i);
                else findOpen(i);
            }
            else {
                
                if(sing> 0 ) findOpen(i) , sing--;
                else findClose(i);

            }
        }
//        cout<<" "<<str<<'\n';
        cout<<vec.size()<<'\n';
        for(auto x : vec) cout<<x.uu+1<<" "<<x.vv+1<<'\n';
    }
    return 0;
}