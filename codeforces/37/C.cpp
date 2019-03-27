#include<bits/stdc++.h>
#define pii pair<int,int>
#define uu first
#define vv second
using namespace std;


string ans;
struct node {

	node * next[2];
    bool isLeaf;
    bool dead;
    node() {
		memset(next , 0 , sizeof next);
		isLeaf = 0;
		dead = 0;
    }
}*root;

int n;
vector<pii>v;
string ara[2000];



bool Insert(node *rt , int lvl) {

	if(lvl == 0 ) {
		rt->isLeaf = true;
		rt->dead = true;
		return true;
	}
	bool ret = false;
    for(int i =0 ; i < 2; i++ ) {

        if( rt->next[i] == 0 ) {
			rt->next[i] = new node();
        }
        if( rt->next[i]->isLeaf == false && rt->next[i]->dead == false) {
            ans += char(i + '0');
            ret = ( (i == 1) &  Insert(rt->next[i] , lvl-1) );
			break;
        }
    }
    return rt->dead = ret;
}


void dfs(node *rt,int lvl) {

	for(int i =0 ; i < 2 ; i++ ) {
		if( rt->next[i] ) {
			cout<<lvl<<" -> "<<i<<" "<<endl;
			dfs(rt->next[i], lvl + 1);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
    for(int  i =0 ; i < n ; i++ ) {
		int tmp;
		cin>>tmp;
		v.push_back({tmp,i});
    }
    sort(v.begin() , v.end());

    root = new node();

    for(int i =0 ; i < n ; i++ ) {
		int len = v[i].uu;
        int id = v[i].vv;

        ans = "";

        bool dead = Insert(root , len);
//        cout<<endl;
//        dfs(root , 1);
//        cout<<endl;

        if( ans.size() <len ) {
			cout<<"NO"<<endl;
			return 0;
        }
        ara[id] = ans;
    }

    cout<<"YES"<<endl;
    for(int i =0 ; i < n ; i++ ) {
		cout<<ara[i]<<'\n';
    }
    return 0;
}
