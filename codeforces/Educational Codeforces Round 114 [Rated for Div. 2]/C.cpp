//#include <bits/stdc++.h>
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>

#include <map>
#include <set>

#include <stack>
#include <queue>

#include <unordered_map>
#include <unordered_set>

//#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

vector<ll> a;
vector<ll> b;
ll n, m;
string s;

void solve(){
    a.clear(); b.clear();
    ll sum = 0;

    cin>>n;
    for(int i = 0; i < n; i++){
        ll z; cin>>z;

        a.push_back(z);
        b.push_back(z);

        sum += z;
    }

    sort(all(a));
    sort(all(b), greater<ll>());

    cin>>m;
    while(m--){
        ll x, y; cin>>x>>y;
        ll ans = LLONG_MAX;

        auto killer = lower_bound(all(a), x);
        if(killer != a.end()){
            ll strength = sum - *killer;
            ll current_ans = 0;
            if(strength < y)
                current_ans += y - strength;

            ans = min(ans, current_ans);
        }

        killer = lower_bound(all(b), x, greater<ll>());
        if(killer != b.end()){
            ll strength = sum - *killer;
            ll current_ans = x - *killer;
            if(strength < y)
                current_ans += y - strength;

            ans = min(ans, current_ans);
        }

        cout<<ans<<"\n";
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

