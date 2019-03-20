#include<bits/stdc++.h>
using namespace std;

struct node {
    node *next[2];
    int cnt;
    node() {
    	memset(next , 0 , sizeof next);
    	cnt = 0;
    }
}*root;


int  n ,m ;

int dfs(node *rt , int num , int no ,int ans)  {

	int id = bool(num&(1<<no));

    if(no == 0) {

    }
}

void Insert(int tmp) {

	node *rt = root;
	rt->cnt++;
    for(int i=20 ; i >=0 ; i-- ) {

        int id = bool(tmp &(1<<i));

        if( rt->next[id] ==0 ) rt ->next[id] = new node();

        rt = rt->next[id];
        rt->cnt++;
    }
}

int query(int num) {

	node *rt = root;
	int ans =0;
    for(int i =20 ; i >=0 ; i--) {

        int tgt = (1<<i);
        int id = bool(num&(1<<i));

        if( rt->next[id] == 0 ) {

            for(int j = i ; j >=0 ; j--) ans *=2;
            return ans;
        }

        if( rt->next[id]->cnt < tgt) ans *=2;
        else {
            ans = (ans<<1|1);
			id^=1;
        }

        if( rt->next[id] == 0 ) {

            for(int j = i -1; j >=0 ; j--) ans *=2;
            return ans;
        }

        rt = rt->next[id];
    }
    return ans;
}
map<int,bool>mp;


void del(node* rt) {
	if(rt->next[0]) del(rt->next[0]);
	if(rt->next[1]) del(rt->next[1]);
	delete rt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	root = new node();
    cin>>n>>m;
    for(int i =0 ; i < n  ; i++ ) {
		int tmp;
		cin>>tmp;
		if(mp.count(tmp) ==0 )Insert(tmp);
		mp[tmp] = 1;
    }

    int tillNow= 0;
    while(m--) {

        int tmp;
        cin>>tmp;
        tillNow ^= tmp;

		cout<<query(tillNow)<<'\n';
    }
    del(root);
    return 0;

}
