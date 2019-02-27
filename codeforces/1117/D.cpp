#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int M = 1e9+7;

struct matrix {
    vector<vector<LL>> v;
    matrix(int n, int m) : v(n, vector<LL>(m)) {}
};

matrix operator * (matrix a, matrix b) {
    int n = a.v.size();
    int m = a.v[0].size();
    assert(b.v.size() == m);
    int k = b.v[0].size();

    matrix ans (n, k);
    for (int i=0; i<n; i++)
        for (int j=0; j<k; j++)
            for (int l=0; l<m; l++)
                ans.v[i][j] = (ans.v[i][j] + a.v[i][l]*b.v[l][j])%M;

    return ans;
}

matrix power(matrix a, LL p) {
    if (p==1)   return a;
    matrix ans = power(a, p/2);
    ans = ans * ans;
    if (p%2)    ans = (ans * a);
    return ans;
}

void print(matrix a) {

    for(int i =0 ; i < a.v.size() ; i++ ) {
        for(int j =0 ; j < a.v[0].size() ; j++ ) {
            cout<<a.v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    LL n , k;
    cin>>n>>k;
    matrix base(k ,k);
    base.v[0][0] = base.v[0][k-1] = 1;

    for(int i =1 ; i<  k ; i++ ) {
        base.v[i][i-1] = 1;
    }

    matrix ans = power(base , n);
    cout<<ans.v[0][0]<<endl;
    return 0;
}