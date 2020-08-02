#include <bits/stdc++.h>

using namespace std;

int main(){
    int m(3), y;
    cin>>y;
    for(int i=2018; i<=y; i+=2){
        if(i==y){
            cout<<"yes\n";
            return 0;
        }
        m+=2;
        if(m>=12){
            i++;
            m%=12;
        }
    }
    cout<<"no\n";
}
