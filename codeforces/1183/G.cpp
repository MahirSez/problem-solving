#include<bits/stdc++.h>
#define MAX 200005
#define uu first
#define vv second

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;

vector<pii>vec ;
map<int,int>mp1 , mp2;




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    
    cin>>t;
    while( t-- ) {
    
        int n;
        cin>>n;
        vec.clear();
        mp1.clear();
        mp2.clear();
        
        for(int i =0 ; i < n ; i++ ) {
            int val , tmp  ;
            cin>>val>>tmp;
            
            mp1[val]++;
            if(tmp) mp2[val]++;
        }
        
        
        priority_queue<pii >pq;
        
        
        for(auto x : mp1) pq.push({x.vv , mp2[x.uu]});
        
        int last = 1E9;
        int ans1 = 0 , ans2 =0;
        
        while( !pq.empty() ) {
            
            int topVal = pq.top().uu;
            int topOne = pq.top().vv;
            
//            cout<<topVal<<" "<<topOne<<endl;
            
            pq.pop();
            
            
            if(topVal > last ) {
                topVal = last;
                topOne = min(topVal , topOne);
                pq.push({topVal , topOne});
                continue;
            }
            
            ans1 += topVal;
            ans2 += topOne;
            last = topVal-1;
            if( last <= 0 ) break;
        }
        cout<<ans1<<" "<<ans2<<'\n';
    }
    return 0;
}
