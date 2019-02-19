#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
map<pii , bool>mp;
int  n ,k;
vector<pii>v;
int main()
{
    cin>>n>>k;
    int cnt = 0;
    int lastX = -1 , lastY = -1;
    for(int i =1 ; i<= k && cnt < n; i++) {

        for(int j = 1 ; j<= k && cnt < n; j++ ) {

            if( i ==j) continue;
            if( lastX ==i || lastY == j) continue;
            if( mp[{i,j}]) continue;

            v.push_back({i,j});
            mp[{i,j}] = true;
            cnt++;
            lastX = i , lastY = j;

            if( mp[{j,i}]) continue;
            v.push_back({j,i});
            mp[{j,i}] = true;
            cnt++;
            lastX = j , lastY = i;
        }
    }

    if( cnt < n) {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i = 0 ; i < n ;i++ ) {
        printf("%d %d\n",v[i].first , v[i].second);
    }
    return 0;
}