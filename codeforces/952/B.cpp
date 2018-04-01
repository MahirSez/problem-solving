#include <bits/stdc++.h>
#define ll          long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0)
using namespace std;
char in[100];
int main()
{
    for(int i =0 ; i < 10 ; i++ ) {

        printf("%d\n",i);
        fflush(stdout);
        cin.getline(in , sizeof(in));
        if( strcmp(in , "cool")==0 || strcmp(in , "not bad")==0 || strcmp(in , "don't think so")==0 || strcmp(in , "don't touch me")==0 || strcmp(in , "great")==0) {
            printf("normal\n");
            fflush(stdout);
            return 0;
        }
        else if( strcmp(in , "terrible")==0 || strcmp(in , "worse")==0 || strcmp(in , "go die in a hole")==0 || strcmp(in , "are you serious?")==0 || strcmp(in , "don't even")==0 || strcmp(in , "no way")==0 ) {
            printf("grumpy\n");
            fflush(stdout);
            return 0;
        }
    }
    return 0;
}
