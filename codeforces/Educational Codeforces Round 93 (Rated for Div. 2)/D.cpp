#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}

vector <ull> r;
vector <ull> g;
vector <ull> b;

void solve(){
    int R, G, B;
    for(int i=0; i<R; i++){
        int z; cin>>z;
        r.push_back(z);
    }
    for(int i=0; i<G; i++){
        int z; cin>>z;
        g.push_back(z);
    }
    for(int i=0; i<B; i++){
        int z; cin>>z;
        b.push_back(z);
    }


}

int main(){
    int t=1;
    while(t--){
        solve();
    }
}
