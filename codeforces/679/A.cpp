#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cnt = 0;
    
    int ara[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
    
    vector<int>tmp;
    for(int i =0  ; i < 15 ; i++ ) {
        
        cout<<ara[i]<<endl;
        string str;
        cin>>str;
        if( str == "yes") tmp.push_back(ara[i]);
    }
    
    if(tmp.size() > 1) {
        cout<<"composite"<<endl;
        return 0;
    }
    if( tmp.size() == 0 ) {
        
        cout<<"prime"<<endl;
        return 0;
    }
    
    int tgt = tmp[0];
    
    if( tgt *tgt <= 100 ) {
        
        cout<<tgt*tgt<<endl;
        string str;
        cin>>str;
        if( str == "yes") {
            cout<<"composite"<<endl;
        }
        else cout<<"prime"<<endl;
    }
    else cout<<"prime"<<endl;
    return 0;
    
}