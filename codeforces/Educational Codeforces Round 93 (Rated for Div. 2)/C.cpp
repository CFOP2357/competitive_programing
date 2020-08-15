#include <bits/stdc++.h>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

inline ull subMod(ull a, ull b){
    return (((a%MOD)+MOD)-(b%MOD))%MOD;
}

vector <int> a;
map<int, ull> m;

void solve(){
    m.clear();
    a.clear();
    int n; cin>>n;
    string s; cin>>s;
    for(char c : s)
        a.push_back(c-'1');

    int sum = 0;
    ull ans = 0;
    m[0] = 1;
    for(int k : a){
        sum += k;
        ans += m[sum];
        m[sum]++;
        //cout<<m[sum]<<"\n";
    }

    cout<<ans<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
}
/*
1
10
90000000000

1
5
10031
*/
