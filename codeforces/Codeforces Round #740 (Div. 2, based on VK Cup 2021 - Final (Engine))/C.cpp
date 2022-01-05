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


ll n, m;
string s;

void solve(){
    cin>>n;

    priority_queue<pii, vector<pii>, greater<pii>> nxt; //power, size

    for(int i = 0; i < n; i++){
        ll k; cin>>k;

        ll max_power = 0;
        for(ll j = 0; j < k; j++){
            ll power; cin>>power;
            power = power - j + 1;

            max_power = max(max_power, power);
        }

        nxt.push({max_power, k});
    }

    ll j = 0, first_power = 0;
    while(nxt.size()){
        auto [power, monsters] = nxt.top();
        nxt.pop();

        first_power = max(first_power, power-j);
        j += monsters;
    }

    cout<<first_power<<"\n";

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
