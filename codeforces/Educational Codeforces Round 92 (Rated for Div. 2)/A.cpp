#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0)
    int t; cin>>t;
    long long l, r;
    while(t--){
        cin>>l>>r;
        //long long g = __gcd(l, r);
        long long k = l*2;
        if(k>r)
            cout<<-1<<" "<<-1<<"\n";
        else
            cout<<l<<" "<<k<<"\n";
    }
    return 0;
}

