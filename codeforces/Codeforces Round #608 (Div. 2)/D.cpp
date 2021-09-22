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

#include <assert.h>

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
typedef int64_t ll;
typedef uint64_t ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

ll n, m, k;

struct Castle{
    ll warriors_to_capture;
    ll avaiable;
    ll importance;
};

vector<bool> selected;
vector<bool> to_select;

vector<pii> order; //importance, idx
vector<Castle> castle;

vector<int> last_portal;
vector<vector<int>> portal;

bool possible_selection(){
    ll warriors = k;

    for(int i = 0; i < n; i++){
        if(warriors < castle[i].warriors_to_capture)
            return false;
        warriors += castle[i].avaiable;

        for(auto to_defend : portal[i]){
            if(selected[to_defend])
                warriors--;
        }
        if(not last_portal[i] and selected[i])
            warriors--;

        if(warriors < 0)
            return false;
    }

    return true;
}

void solve(){
    cin>>n>>m>>k;

    selected.assign(n+1, false);
    to_select.assign(n+1, false);
    last_portal.assign(n+1, 0);
    portal.assign(n+1, vector<int>());

    for(int i = 0; i < n; i++){
        ll a, b, c; cin>>a>>b>>c;

        castle.push_back({a, b, c});
        order.push_back({c, i});
    }
    sort(all(order), greater<pii>());

    while(m--){
        int u, v; cin>>u>>v;
        u--, v--;

        last_portal[v] = max(last_portal[v], u);
    }
    for(int i = 0; i < n; i++){
        if(last_portal[i])
            portal[last_portal[i]].push_back(i);
    }


    if(not possible_selection()){
        cout<<"-1\n";
        return;
    }

    ll ans = 0;
    for(auto [importance, idx] : order){
        selected[idx] = true;
        if(possible_selection())
            ans += importance;
        else
            selected[idx] = false;
    }

    cout<<ans<<"\n";
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

