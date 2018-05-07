#include<bits/stdc++.h>
#define read    freopen("in.txt","r",stdin)
#define write   freopen("out.txt","w",stdout)
#define lli     long long int
#define ld      long double
#define PI 	    acos(-1)
#define INF     1e9
#define uu		first
#define vv		second
//typedef pair<int,int> pii;
using namespace std;

lli n,ara[501],ans,tmp,cnt,sum,dst[501][501];
vector<lli>v;
vector<lli>an;
void floyd() {
    for(lli k=0;k<n;k++) {
        for(lli i=0;i<n;i++) {
            for(lli j=0;j<n;j++) {
                //cout<<dst[v[i]][v[j]]<<endl;
                dst[v[i]][v[j]]=min(dst[v[i]][v[j]],dst[v[i]][v[k]]+dst[v[k]][v[j]]);
                //cout<<v[i]<<" "<<v[j]<<" "<<dst[v[i]][v[j]]<<endl;
            }
        }
        for(lli j=0;j<=k;j++) {
            for(lli i=0;i<=k;i++) {
                ans+=dst[v[i]][v[j]];
                //cout<<ans<<endl;
            }
        }
        an.push_back(ans);
        ans=0;
    }
}



int main()
{
    cin>>n;
    //for(lli i=0;i<n;i++) for(lli j=0;j<n;j++) dst[i][j]=INF;
    v.clear();
    an.clear();

    for(lli i=0;i<n;i++)
        for(lli j=0;j<n;j++) cin>>dst[i][j];

    for(lli i=0;i<n;i++) {
        cin>>tmp;
        v.push_back((tmp-1));
        //cout<<tmp-1<<endl;
    }
    reverse(v.begin(),v.end());
    //for(lli i=0;i<v.size();i++) cout<<v[i]<<" ";
    floyd();

    for(lli i=an.size()-1;i>=0;i--) cout<<an[i]<<" ";
    return 0;
}

