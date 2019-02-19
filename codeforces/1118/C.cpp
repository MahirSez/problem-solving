#include<bits/stdc++.h>
#define pii pair<int,int>
#define uu first
#define vv second
using namespace std;
int ara[50][50];

int n , str[20000];
priority_queue<pii>pq;

void print() {

    for(int i =0 ; i < n ; i++ ) {
        for(int j = 0 ; j < n ; j++ ) {
            cout<<ara[i][j]<<" ";
        }
        cout<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    for(int i =0 ; i < n * n ; i++  ) {
        int tmp;
        cin>>tmp;
        str[tmp] ++;
    }

    for(int i =1 ; i<= 2000; i++ ) {
        if( str[i]) pq.push({str[i] , i});
    }

    for(int i =0 ; i < n/2 ; i++ ) {

        for(int j = 0 ; j < n/2 ; j++ ) {

            int fre = pq.top().uu;
            int num = pq.top().vv;
            pq.pop();

            if( fre < 4) {
                cout<<"NO"<<endl;
                return 0;
            }

            ara[i][j] = num;
            ara[i][n - 1 - j] = num;
            ara[n - i - 1][j] = num;
            ara[n - i - 1][n - 1 - j] = num;
            fre -=4;

            if(fre)  pq.push({fre,num});
        }
    }

    if( n %2 ==0) {
        cout<<"YES"<<endl;
        print();
        return 0;
    }

    for(int i =0 ; i < n/2 ; i++ ) {

        int fre = pq.top().uu;
        int num = pq.top().vv;
        pq.pop();

        if( fre < 2)  {
            cout<<"NO"<<endl;
            return 0;
        }

        ara[n/2][i] = num;
        ara[n/2][n -1 -i] = num;
        fre -= 2;

        if( fre) pq.push({fre , num});
    }

    for(int i =0 ; i < n/2 ; i++ ) {

        int fre = pq.top().uu;
        int num = pq.top().vv;
        pq.pop();

        if( fre < 2)  {
            cout<<"NO"<<endl;
            return 0;
        }

        ara[i][n/2] = num;
        ara[n-i-1][n/2] = num;
        fre -= 2;

        if( fre) pq.push({fre , num});
    }

    int num = pq.top().vv;
    ara[n/2][n/2] = num;
    cout<<"YES"<<endl;
    print();

    
    return 0;
}