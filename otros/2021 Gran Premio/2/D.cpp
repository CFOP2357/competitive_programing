#include <bits/stdc++.h>

using namespace std;

#define all(container) begin(container), end(container)

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const int MAX = 1e6;
const int MOD = 1e9 + 7;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using orderedSet = tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update>;
using orderedMultiSet = tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update>;
*/

/////////////////From KACTL/////////////////
// Source: https://github.com/kth-competitive-programming/kactl

///////////////////////////////////////////////////

void preprocessing(){
    return;
}

void solve(){
    ll c, r, s;

    cin >> c >> r >> s;

    ll total_spoons = ((c+r) / s);
    if((c+r) % s > 0)
      total_spoons++;

    ll max_o = total_spoons - r/s;
    if(r%s)
      max_o--;
    max_o = max(max_o, 0LL);

    ll min_o = max(total_spoons - r, 0LL);

    cout << max_o << ' ' << min_o << '\n';
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin.exceptions(cin.failbit);

    //srand (time(nullptr));

    preprocessing();

    int t=1;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}

/*
3
9 2 2
10 10 1
13 0 3
*/
