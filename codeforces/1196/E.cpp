#include<bits/stdc++.h>
using namespace std;
int b , w;


int main()
{
    int t;
    cin>>t;
    while(t-- ) {
        cin>>b>>w;
        
        vector<int>bk , wt;
        if( b > 3*w + 1 ||  w > 3*b+1)  {
            cout<<"NO\n";
            continue;
        }
        
        cout<<"YES\n";
        for(int i = ((w<b)? 2:3) ; b > 0 && w > 0 ; i++ ) {
            
            if(i &1 ) b--;
            else w--;
            
            cout<<2<<" "<<i<<'\n';
            
            if( i &1 ) bk.push_back(i);
            else wt.push_back(i);
        }
        
        for(int i =0 ; i < wt.size() && b> 0 ; i++ , b--) {
            cout<<1<<" "<<wt[i]<<'\n';
        }
        for(int i =0 ; i < wt.size() && b> 0 ; i++ , b--) {
            cout<<3<<" "<<wt[i]<<'\n';
        }
        for(int i =0 ; i < bk.size() && w> 0 ; i++ , w--) {
            cout<<1<<" "<<bk[i]<<'\n';
        }
        for(int i =0 ; i < bk.size() && w> 0 ; i++ , w--) {
            cout<<3<<" "<<bk[i]<<'\n';
        }
        
        if(b>0) {
            cout<<2<<" "<<wt[0]-1<<'\n';
            b--;
        }
        if(b>0) {
            cout<<2<<" "<<wt[wt.size()-1]+1<<'\n';
            b--;
        }
        
        if( w > 0) {
            
            cout<<2<<" "<<bk[0] - 1<<'\n';
            w--;
        }
        if( w > 0 ) {
            
            cout<<2<<" "<<bk[bk.size()-1]+1<<'\n';
            w--;
        }
        
        assert(b==0 && w ==0 );
    }
    return 0;
    
}