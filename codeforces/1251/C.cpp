#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define INF         1e9
#define MOD         1000000007
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const int MAX = 1e6 + 6;
int main()
{
    fastRead;
    int t;
    cin>>t;
    while(t--) {
        
        string str;
        cin>>str;
        queue<int>q1 , q2;
        for(auto x : str){
            int id = x - '0';
            if(id&1) q1.push(id);
            else q2.push(id);
        }
        
        while(!q1.empty() && !q2.empty()) {
            
            if(q1.front() > q2.front()) {
                cout<<q2.front();
                q2.pop();
            }
            else {
                cout<<q1.front();
                q1.pop();
            }
        }
        while(!q1.empty()) {
            cout<<q1.front();
            q1.pop();
        }
        while(!q2.empty()) {
            cout<<q2.front();
            q2.pop();
        }
        cout<<'\n';
    }
    return 0;
}