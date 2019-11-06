#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define ppi         pair<pii,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

int l , b , f ;

vector<ppi>vec;

int solve(int len , int id) {

    if(vec.size() == 0) {
        if(len <= l ) {
            vec.push_back({ {0 , len} , id});
            return 0;
        }
        return -1;
    }
    
    sort(vec.begin() , vec.end());
    
    
    int nn = vec.size();
    
    if(len + f <= vec[0].uu.uu) {
        vec.push_back({{0 , len} , id});
        return 0;
    }
    
    for(int i =0 ; i < nn-1 ; i++) {
        
        int bb = vec[i].uu.vv;
        int ff = vec[i+1].uu.uu;
        
        if(ff - bb >= len + f + b ) {
            vec.push_back({ { bb + b , bb + b + len} , id});
            return bb + b;
        }
    }
    
    if(len + b + vec[nn-1].uu.vv <= l) {
        vec.push_back({ { b + vec[nn-1].uu.vv, len + b + vec[nn-1].uu.vv} , id});
        return b + vec[nn-1].uu.vv;
    }
    
    return -1;
    
}

void Remove(int id) {
    
    vector<ppi>tmp;
    
    for(auto x : vec) {
        if(x.vv == id) continue;
        tmp.push_back(x);
    }
    vec = tmp;
}
//
//void print() {
//
//    for(auto x : )
//}


int main()
{
    fastRead;
    
    int n;
    cin>>l>>b>>f>>n;
    
    int cnt= 0;
    for(int i =1 ; i <=n ; i++ ) {
        
        int typ ;
        cin>>typ;
        if(typ == 1) {
            
            int val;
            cin>>val;
            cout<<solve(val , i)<<'\n';
        }
        else {
            int id;
            cin>>id;
            Remove(id);
        }
//        print();
    }
    return 0;
}
