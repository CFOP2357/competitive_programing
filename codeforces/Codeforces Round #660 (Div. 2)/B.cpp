#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        long long n; cin>>n;
        long long firstPart = n;
        long long ans  = 0;
        while(firstPart>0){
            ans++;
            firstPart -= 4;
            n--;
        }
        while(n--)cout<<9;
        while(ans--)cout<<8;
        cout<<"\n";
    }
    return 0;
}
