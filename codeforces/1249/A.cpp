#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int t;
    scanf("%d",&t);
    while(t--) {
        int n;
        vector<int>vec;
        scanf("%d",&n);
        
        for(int i =0 ; i < n ; i ++ ) {
            int tmp;
            scanf("%d",&tmp);
            vec.push_back(tmp);
        }
        sort(vec.begin() , vec.end() );
        int ans = 1;
        
        for(int i =1 ; i < n ; i++ ) {
            if(vec[i] == vec[i-1] + 1) {
                ans++;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}