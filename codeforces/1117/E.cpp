#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	100005
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

string str;
int ara[MAX][3] , input[MAX][3];

bool same(int id1 , int id2) {
    for(int i =0 ; i < 3 ; i++ ) {
        if( ara[id1][i] != input[id2][i] ) return false;
    }
    return true;
}


int n;
int main()
{
    cin>>str;
    n = str.size();

    int cnt =0;

    for(int i = 0 ; i < 26 && cnt < n; i++ ) {

        for(int j =0 ; j < 26 && cnt < n ; j++ ) {
            
            for(int k = 0 ; k < 26 && cnt < n ; k++) {
                
                ara[cnt][0] = i;
                ara[cnt][1] = j;
                ara[cnt++][2] = k;
            }
        }
    }

    for(int i =0 ; i < 3 ; i++ ) {
        cout<<"? ";
        for(int j =0 ; j < n ; j++ ) {
            cout<<(char)(ara[j][i] +'a');
        }
        cout<<endl;

        string tmp;
        cin>>tmp;
        for(int j =0 ; j< n ; j++ ) {
            input[j][i] = tmp[j] - 'a';
        }
    }

    // for(int i =0 ; i < n ; i++ ) {
    //     cout<<char(input[i][3] +'a')<<" ";
    // }

    for(int i =0 ; i < n ; i++ ) {

        for(int j =0 ; j < n ; j++ ) {

            if( same(i , j) ) {
                swap(str[i] , str[j]);
                swap(input[i][0] , input[j][0]);
                swap(input[i][1] , input[j][1]);
                swap(input[i][2] , input[j][2]);
            }
        }
    }

    cout<<"! "<<str<<endl;

    return 0;
}