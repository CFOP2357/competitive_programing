#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}

vector <ull> a;
vector <ull> b;

void solve(){
    int n; cin>>n;
    string s; cin>>s;
    for(int i=0; i<n*2-1; i+=2){
        cout<<s[i];
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    LLONG_MAX;
}
