#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
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

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 300100
#define MOD 1000000007

vector<vector<ull>> adj;
vector<vector<ull>> inv;
vector<ull> order;
vector<bool> visited;

ull n;

void topSort(int v){

    if(visited[v])
        return;
    visited[v] = true;

    for(int u : inv[v])
        topSort(u);

    order.push_back(v);

}

ull dfs(int v){
    if(visited[v])
        return 0;
    visited[v] = true;

    ull ans = 0;
    for(int u : adj[v])
        ans += dfs(u);

    return 1 + ans;

}

void solve(){
    order.clear();

    cin>>n;
    string s; cin>>s;

    adj.assign(n+5, vector<ull>());
    inv.assign(n+5, vector<ull>());
    visited.assign(n+5, false);

    for(int i=0; i<n; i++){
        if(s[i] == '-' || s[i]=='>'){
            adj[i].push_back((i+1)%n);
            inv[(i+1)%n].push_back(i);
        }
        if(s[i] == '-' || s[i]=='<'){
            adj[(i+1)%n].push_back(i);
            inv[i].push_back((i+1)%n);
        }
    }

    for(int i=0; i<n; i++)
        topSort(i);
    reverse(all(order));

    ull ans = 0;
    fill(all(visited), false);
    for(int v : order){
        ull d = dfs(v);
        if(d > 1)
            ans += d;
    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

