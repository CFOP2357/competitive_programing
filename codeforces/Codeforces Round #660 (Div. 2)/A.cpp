#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    int n;
    while(t--){
        cin>>n;
        if(n<=30){
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
            int a(6), b(14), c(10);
            int dif = n-a-b-c;
            if(dif==a)
                b=15;
            else if(dif==b)
                b=15;
            else if(dif==c)
                b=15;
            dif = n-a-b-c;
            cout<<a<<" "<<b<<" "<<c<<" "<<dif<<"\n";
        }
    }
    return 0;
}
