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
int reply[10] , ans[10] , rec[100] , ara[10];
int main()
{
    cout<<"? 1 2"<<endl;
    cin>>reply[1];
    cout<<"? 2 3"<<endl;
    cin>>reply[2];

	cout<<"? 4 5"<<endl;
    cin>>reply[3];
    cout<<"? 5 6"<<endl;
    cin>>reply[4];


	ara[1] = 4;
	ara[2] = 8;
	ara[3] = 15;
	ara[4] = 16;
	ara[5] = 23;
	ara[6] = 42;




//    for(int i = 1 ; i<= 6 ; i++ ) {
//
//        if(reply[1]%ara[i] ==0 && reply[2]%ara[i] ==0 && rec[reply[1]/ara[i]] && rec[reply[2]/ara[i]]) {
//            ans[2] = ara[i];
//            ans[1] = reply[1]/ara[i];
//            ans[3] = reply[2]/ara[i];
//
//
//            break;
//        }
//    }
//
//    for(int i = 1 ; i<= 6 ; i++ ) {
//
//        if(reply[3]%ara[i] ==0 && reply[4]%ara[i] ==0 && rec[reply[3]/ara[i]] && rec[reply[4]/ara[i]]) {
//            ans[5] = ara[i];
//            ans[4] = reply[3]/ara[i];
//            ans[6] = reply[4]/ara[i];
//            break;
//        }
//    }




	for(int i =1 ; i<= 6 ; i++ ) {
		for(int j =1 ; j<= 6 ; j++ ) {

//			cout<<i<<" "<<j<<endl;

			if( i ==j ) continue;

			for(int k =1 ; k<= 6 ; k++ ) rec[ara[k]] = 1;
			bool ok = true;


//			cout<<ara[i]<<endl;


			if(reply[1]%ara[i] ==0 && reply[2]%ara[i] ==0 && rec[reply[1]/ara[i]]==1 && rec[reply[2]/ara[i]]==1) {
//					cout<<ara[i]<<endl;

				ans[1] = reply[1]/ara[i];
				ans[2] = ara[i];
				ans[3] = reply[2]/ara[i];

//				cout<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;

                rec[ans[1]] = 0;
                rec[ans[2]] = 0;
                rec[ans[3]] = 0;

                if(rec[ara[j]] && reply[3]%ara[j] ==0 && reply[4]%ara[j] ==0 && rec[reply[3]/ara[j]] && rec[reply[4]/ara[j]]) {

					ans[4] = reply[3]/ara[j];
					ans[5] = ara[j];
					ans[6] = reply[4]/ara[j];

					rec[ans[4]] = 0;
					rec[ans[5]] = 0;
					rec[ans[6]] = 0;
                }
			}


			for(int i =1 ; i<= 6 ; i++ ) if( rec[ara[i]]) ok = false;
            if( ok ) {
				cout<<"!";
				for(int k =1 ; k <=6 ; k++) cout<<" "<<ans[k];
				cout<<endl;
				return 0;
            }
		}
	}

	assert(0);
	return 0;
}

/*
32
120
368
966
*/
