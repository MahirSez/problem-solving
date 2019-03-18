#include<bits/stdc++.h>
#define MAX 100005
#define pii pair<int,int>
#define uu first
#define vv second
using namespace std;
int ans =0 ;
vector<pii>v;

set<int>r[MAX] , b[MAX];
vector<string>red , blu;
int n;

struct node{
    int blu , red ;
    int redMarker, bluMarker;
    int lvl;
    node* next[27];
    node() {
    	blu = 0;
    	red = 0;
    	redMarker = -1;
    	bluMarker = -1;
    	memset(next , 0 , sizeof next);
    }
}*root;


int insertRed(string &str,int idd) {

	node *rt = root;
	rt->lvl = 0;

	rt->red++;
    for(int i =0 ; i < str.size() ; i++ ) {

        int id = str[i]- 'a';
        if( rt->next[id] ==0 ) rt->next[id] = new node();


		rt->next[id]->lvl = rt->lvl + 1;
        rt = rt->next[id];
        rt->red++;

    }
	if( rt->redMarker == -1 ) rt->redMarker = idd;
	return rt->redMarker;
}

int insertBlu(string &str , int idd){

	node *rt = root;
	rt->lvl = 0;

	rt->blu++;

	for(int i =0 ; i < str.size() ; i++ ) {

		int id = str[i] - 'a';

        if( rt->next[id] ==0 ) rt->next[id] = new node();

		rt->next[id]->lvl = rt->lvl + 1;
        rt = rt->next[id];
        rt->blu++;
	}

	if( rt->bluMarker == -1 ) rt->bluMarker = idd;
    return rt->bluMarker;
}
void print() {

	for(int i = 0 ; i < n ; i++) {
		cout<<i <<"-> ";
		for(auto x : r[i]) cout<<x<<" ";
		cout<<endl;
	}
	cout<<endl;
	for(int i = 0 ; i < n ; i++) {
		cout<<i <<"-> ";
		for(auto x : b[i]) cout<<x<<" ";
		cout<<endl;
	}
	cout<<endl;


}

int dfs2(node *rt) {


	rt->red--;
    if( rt->redMarker != -1) {

        int id = rt->redMarker;

		int redAns = *r[id].begin();
		r[id].erase(*r[id].begin());

		if( r[id].empty()) rt->redMarker = -1;
		return redAns;
    }

    for(int i = 0; i < 26 ; i++ ) {
        if( rt->next[i] && rt->next[i]->red > 0 ) {

			return dfs2(rt->next[i]);
        }
    }
}

int dfs3(node *rt) {

	rt->blu--;
	if( rt->bluMarker != -1) {

        int id = rt->bluMarker;

        int bluAns = *b[id].begin();
        b[id].erase(*b[id].begin());

        if( b[id].empty()) rt->bluMarker = -1;
        return bluAns;
	}


	for(int i =0 ; i < 26 ; i++ ) {
		if( rt->next[i] && rt->next[i]->blu > 0) {
			return dfs3(rt->next[i]);
		}
	}

}


void dfs1(node *rt) {


	bool ok = false;
    for(int i =0 ; i < 26; i++) {

		if( rt->next[i] == 0) continue;

        if( rt->next[i]->blu >0 && rt->next[i]->red >0 ) {
			dfs1(rt->next[i]);
			ok = true;
			break;
        }
    }


	if( ok == false) {

        ans += rt->lvl;


        int redAns = -1 , bluAns = -1;

        if( rt->redMarker != -1) {

            int id = rt->redMarker;
            redAns = *r[id].begin();
            r[id].erase(*r[id].begin());


            if( r[id].empty()) rt->redMarker = -1;

        }
        else {
			for(int i =0 ; i < 26 ; i++ ) {

				if( rt->next[i] && rt->next[i]->red > 0) {
					redAns = dfs2(rt->next[i]);
					break;
				}
			}
        }

        if( rt->bluMarker != -1) {

			int id = rt->bluMarker;

			bluAns = *b[id].begin();
			b[id].erase(*b[id].begin());

			if( b[id].empty() ) rt->bluMarker = -1;
        }

        else {
            for(int i =0 ; i < 26 ; i++ ) {
				if( rt->next[i] &&rt->next[i]->blu > 0) {
					bluAns = dfs3(rt->next[i]);
					break;
				}
            }
        }

//		cout<<redAns<<" "<<bluAns<<endl;
//		cout<<red[redAns]<< " "<<blu[bluAns]<<" "<<rt->lvl<<endl;
//		print();
        v.push_back({redAns+1 , bluAns+1});
	}


    rt->red--;
    rt->blu--;
//    cout<<rt->lvl<<" "<<rt->red<<" "<<rt->blu<<endl;

}





void del(node *root) {

	for(int i =0 ; i < 26 ; i++ ) {
		if( root->next[i]) del(root->next[i]);
	}
	delete root;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	root = new node();
	cin>>n;


    for(int i =0 ; i < n ; i++ ) {
		string str;
		cin>>str;
		red.push_back(str);

        int ret = insertRed(str , i);
		r[ret].insert(i);

    }

    for(int i = 0 ; i < n ; i++ ) {
		string str;
		cin>>str;
		blu.push_back(str);

		int ret = insertBlu(str,i);
		b[ret].insert(i);

    }
//	print();


    for(int i =0 ; i < n ; i++ ) {
		dfs1(root);
    }


	cout<<ans<<endl;
	for(int i =0 ; i < v.size() ; i++ ) {
		cout<<v[i].uu<<" "<<v[i].vv<<" "<<'\n';
	}
	del(root);
	return 0;
}



