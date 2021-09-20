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

#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define all(a) a.begin(), a.end()

typedef int ull;
typedef int ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<pii> segment;
vector<ll> a;
ull n, m, k;
ll ans;

unordered_map<int, vector<int>> adj;

unordered_map<int, bool> selected;
void exahustive_search(int current, int first_node, int points=0){
    int v = current;

    if(selected[v])
        return;

    bool is_inside = (segment[v].first <= points and points <= segment[v].second);
    if(current != first_node and not is_inside)
        return;

    //cout<<current<<"$\n";

    bool possible_to_pass = (first_node == current);
    for(auto u : adj[v]){
        if(selected[u])
            possible_to_pass = true;
    }
    if(not possible_to_pass)
        return;

    points += a[current];

    if(points == k)
        ans++;
    if(points >= k)
        return;

    selected[v] = true;

    for(int u = 0; u < n; u++)
        exahustive_search(u, first_node, points);

    selected[v] = false;
}

void solve(){
    adj.clear(); segment.clear(); a.clear(); selected.clear();
    cin>>n>>m>>k;

    for(int i=0; i<n; i++){
        ll l, r, a; cin>>l>>r>>a;

        segment.push_back({l, r});
        ::a.push_back(a);
    }

    for(int i=0; i<m; i++){
        ll x, y; cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ans = 0;

    for(int v = 0; v < n; v++)
        exahustive_search(v, v);

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}

/*
1
4 3 3
1 3 1
1 1 1
2 4 1
2 3 1
0 1
1 2
2 3

1
4 1 2
0 4 1
0 4 1
0 4 2
0 4 2
0 1
*/
