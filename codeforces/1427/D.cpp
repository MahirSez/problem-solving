#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef tuple<int, int,int> tp;

const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int N = 1e6 + 6;

int n;
int ara[60], pos[60];


vector< vector<int> >ans;
int ok() {
    assert(ans.size() <= n);
    for(int i =1; i <= n ; i++ ) {
        if(ara[i] != i) return 0;
    }
    return 1;
}

void print() {
    cout<<ans.size()<<'\n';
    for(auto x : ans) {
        cout<<x.size()<<" ";
        for(auto xx : x) cout<<xx<<" ";
        cout<<'\n';
    }
}

void updatepos() {
    for(int i =1 ; i <=n ; i++ ) pos[ara[i]] = i;
}

void change(int l1, int r1 , int l2, int r2) {

    int val1 = r1 - l1 + 1;
    int val2 = r2 - (r1 + 1) + 1;

    vector<int>change;

    if(l1 > 1) change.push_back(l1-1);
    change.push_back(val1);
    change.push_back(val2);
    if(r2 < n ) change.push_back(n - (r2+1) +1 );




    vector<int>tmp;
    for(int i =1 ; i <=n ; i++ ) tmp.push_back(ara[i]);

    // reverse(tmp.begin() , tmp.end());

    ans.push_back(change);
    int till = 0;

    while(tmp.size()) {
        int val = change.back();
        change.pop_back();
        vector<int>rec;
        while(val--) {
            rec.push_back(tmp.back());
            tmp.pop_back();
        }
        reverse(rec.begin() , rec.end());

        // cout<<rec.size()<<'\n';
        for(int i = 0 ; i < rec.size() ; i++ ) {
            ara[++till] = rec[i];            
        }
    }

    // for(int i =1; i<=n ; i++ ) cout<<ara[i]<<" ";
    // cout<<'\n';
    // cout<<'\n';
}

int main() {
    cin>>n;

    for(int i =1 ; i <= n ; i++ ) cin>>ara[i];
    updatepos();


    while(1) {
        if(ok()) {
            print();
            return 0;
        }

        int val1 = -1 , val2 = -1;

        for(int i = 1 ; i < n   ; i++) {
            if(pos[i] > pos[i + 1]) {
                val1 = i+1;
                val2 = i;
                break;
            }
        }
        //val1 > val2

        
        int l1 = pos[val1] , r1 = pos[val1];
        int l2 = pos[val2] , r2 = pos[val2];

        while(r1 +1<=n && pos[ara[r1] + 1] == pos[ara[r1]] + 1) r1++;
        while(l2 -1 >= 1 && pos[ara[l2] - 1] == pos[ara[l2]] -1 ) l2--;

        // cout<<val1<<" "<<val2<<'\n';
        // cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<'\n';
        

        change(l1 , r1 , l2 , r2);


        updatepos();



    }
    return 0;
    
}