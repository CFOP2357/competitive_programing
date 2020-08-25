#include <iostream>
#include <vector>
using namespace std;

#define MAX 3010
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return ((a+MOD)-b)%MOD;
}

vector <ull> a;
vector <ull> b;

ull l[MAX];
ull r[MAX];

void solve(){
    int n; cin>>n;
    a.clear();
    fill(l, l+MAX, 0);
    for(int i=0; i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }

    ull ans = 0;
    for(int i=0; i<n; i++){
        fill(r, r+MAX, 0);

        for(int j=n-1; j>i; j--){
            ans += r[a[i]]*l[a[j]];
            r[a[j]]++;
        }

        l[a[i]]++;

    }

    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}
