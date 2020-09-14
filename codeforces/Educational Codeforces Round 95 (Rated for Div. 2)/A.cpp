#include <iostream>
#include <climits>
using namespace std;

typedef unsigned long long ull;


#define MAX 1000100
#define MOD 1000000007

ull x, y, k;

void solve(){

    ull ans = 0;

    cin>>x>>y>>k;

    ull s = k;

    s += y*k;
    ans += k;

    //s = 1000000000000000000000;
    //cout<<s<<" ";
    s--; x--;
    if(s%x) s += x;
    ans += s/x;

    cout<<(ull)ans<<"\n";



}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

