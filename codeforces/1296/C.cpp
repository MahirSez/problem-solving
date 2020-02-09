#include<bits/stdc++.h>
#define ll long long int
#define pii pair<int,int>
using namespace std;
int main()
{
        
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        
        int n;
        cin>>n;
        string str;
        cin>>str;
        map<pii , int>mp;
        
        int nx = 0 , ny = 0;
        int id = 1;
        
        int len = 1e9;
        int frm = -1 , to = -1;
        mp[{nx, ny}] = 1;
        
        
        for(auto x : str) {
            
            if(x == 'L') nx--;
            if(x == 'R') nx++;
            if(x == 'U') ny++;
            if(x == 'D') ny--;
            id++;
            
            int tmp = mp[{nx , ny}];
            
//            cout<<tmp<<" "<<id<<" "<<len<<'\n';
            
            if(tmp && (id - tmp) < len) {
                len = id - tmp;
                frm = tmp;
                to = id-1;
            }
            mp[{nx , ny}] = id;

        }
        if(frm == -1) cout<<-1<<'\n';
        else cout<<frm<<" "<<to<<'\n';
    }
    return 0;
}

/*
1
6
LLRRUD
*/
