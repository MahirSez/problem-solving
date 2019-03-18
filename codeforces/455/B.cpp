#include<bits/stdc++.h>
using namespace std;

struct node {
    node* next[27];
    int lvl;
    node() {
		memset(next , 0 , sizeof next);
		lvl = 0;
    }
}* root;
int  n, k;


void Insert(string &str) {

    node *rt = root;
    rt->lvl = 0;

    for(int i = 0 ; i < str.size() ; i++ ) {
        int id = str[i]-'a';
        if( rt -> next[id] == 0 ) rt ->next[id] = new node();

		rt->next[id]->lvl = rt->lvl + 1;
        rt = rt->next[id];
    }
}


bool dfs1(node *rt , int turn) {

    bool more = false;

	for(int i =0 ; i < 26 ; i++ ) {
        if( rt->next[i] == 0 ) continue;
        more = true;
	}
	if( more == false) return true;

	bool win = true;
	for(int i = 0 ; i < 26 ; i++ ) {

		if( rt->next[i] == 0) continue;

		win = (win & (dfs1(rt->next[i] , turn^1)^1) );
	}
	return win;
}

bool dfs2(node *rt  , int turn) {

    bool more =false;

    for(int i =0 ; i < 26 ; i++ ) {
        if( rt->next[i] == 0 ) continue;
        more = true;
	}
	if( more == false ) return false;

	bool lose = true;

    for(int i =0 ; i < 26 ; i++) {

        if( rt->next[i] == 0 ) continue;

        lose = (lose & (dfs2(rt->next[i] , turn^1)^1 ) );
    }
    return lose;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	root = new node();

	cin>>n>>k;
	for(int i =0 ; i < n ; i++ ) {
		string str;
		cin>>str;
		Insert(str);
	}

    bool ret1 = false;
    for(int i = 0 ; i < 26 ; i++ ) {
		if( root->next[i] == 0) continue;
		ret1 |= dfs1(root->next[i] , 0);
    }

    bool ret2 = false;
    for(int i = 0; i < 26 ; i++) {
		if( root->next[i] ==0 ) continue;
		ret2 |= dfs2(root->next[i] , 0);
    }


    if( ret1 && ret2 ) cout<<"First"<<endl;
    else if( ret1 == 0 ) cout<<"Second"<<endl;
    else if(k %2 )	cout<<"First"<<endl;
    else cout<<"Second"<<endl;
    return 0;
}


