#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e9
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;

vector<int>rec[MAX];


int ask(vector<int>&vec) {
    
    cout<<"? "<<vec.size()<<" ";
    for(auto x : vec) cout<<x<<" ";
    cout<<endl;
    int ret;
    cin>>ret;
    return ret;
}

int get(int frm, int to) {
    
    vector<int>vec;
    for(int i = frm ; i <=to ; i++ ) {
        for(auto x : rec[i]) vec.push_back(x);
    }
    return ask(vec);
}


int main()
{
    int t;
    cin>>t;
    while(t--)  {
            
            
        int n, k;
        cin>>n>>k;
        for(int i =1 ; i <=k ; i++) {
            int tmp;
            cin>>tmp;
            rec[i].clear();
            while(tmp--) {
                int id;
                cin>>id;
                rec[i].push_back(id);
            }
        }
        
        vector<int>vec;
        for(int i =1 ; i <=n ; i++ ) vec.push_back(i);
        int mxEle = ask(vec);
        int lo = 1, hi = k, mxId= 1;
        
        while(lo <= hi) {
            
            
            int mid = (lo+hi)/2;
            
            int ret = get(lo, mid);
            if(ret == mxEle) {
                hi = mid-1;
                mxId = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        assert(mxId != -1);
        
        int mxAns = -1;
        
        vec.clear();
        for(int i =1 ; i <=n ; i++ ) {
            
            bool ok = 1;
            for(auto x : rec[mxId]) {
                if(x == i) ok = 0;
            }
            if(ok) vec.push_back(i);
        }
        mxAns = ask(vec);
        
        cout<<"! ";
        for(int i = 1 ; i <= k ; i++) {
            if(i == mxId) cout<<mxAns<<" ";
            else cout<<mxEle<<" ";
        }
        cout<<endl;
        string ret;
        cin>>ret;
        if( ret == "Incorrect") break;
    }
    return 0;
}