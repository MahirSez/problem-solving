#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define pll			pair<ll,ll>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
int n ;
string s , t;
vector<int>v1 , v2,sum;
int main()
{
	cin>>n>>s>>t;
	for(char x : s) {
        v1.push_back(x-'a');
	}
	for(char x : t) {
		v2.push_back(x-'a');
	}
	int carry = 0;
	for(int i =n-1 ; i >= 0 ; i--) {


        sum.push_back((carry + v1[i] + v2[i])%26);
        carry = (carry + v1[i] + v2[i])/26;
	}
	reverse(sum.begin() , sum.end() );

    int rem = carry;

    for(int i =0 ; i <n ; i++ ) {


        int id = (rem*26 + sum[i])/2;

//		cout<<endl<<id<<endl;
        rem = sum[i]&1;



        cout<<char(id+'a');

    }
	cout<<endl;
	return 0;

}
