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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef int64_t ll;
typedef uint64_t ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

vector<ll> a;
vector<ll> b;
ll n, m;
string s;

vector<vector<int>> adj;
vector<int> black;
vector<int> white;

map<int, bool> visited;

void visit(int v, bool is_white=true){
    if(visited[v])
        return;
    visited[v] = true;

    if(is_white)
        white.push_back(v);
    else
        black.push_back(v);

    for(int u : adj[v])
        visit(u, (not is_white));
}
void solve(){
    adj.clear();
    black.clear();
    white.clear();
    visited.clear();

    cin>>n;

    deque<int> ans(n+1, 0);

    adj.assign(n+1, vector<int>());
    for(int i = 1; i < n; i++){
        int u, v; cin>>u>>v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    visit(rand()%n + 1);

    if(black.size() > white.size())
        swap(black, white);

    int i;
    for(i = 1; black.size(); i++){
        ans[black.back()] = i;
        black.pop_back();
    }

    reverse(all(white));
    for(; white.size(); i++){
        ans[white.back()] = i;
        white.pop_back();
    }

    ans.pop_front();
    for(auto k : ans)
        cout<<k<<" ";
    cout<<"\n";
}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

