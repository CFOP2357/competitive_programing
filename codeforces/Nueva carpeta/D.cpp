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

vector<vector<int>> imposter_adj;
vector<vector<int>> crewmate_adj;
ll n, m;

ll color1(0), color2(0);

ll ans;
vector<int> color;
void dfs(int v=1, int current_color=1){
    if(color[v]){
        if(color[v] != current_color)
            ans = -1;
        return;
    }

    color[v] = current_color;
    if(current_color == 1)
        color1++;
    else
        color2++;

    for(auto crewmate : crewmate_adj[v]){
        dfs(crewmate, current_color);

        if(ans == -1)
            return;
    }

    int other_color = 1;
    if(current_color == 1)
        other_color = 2;
    for(auto imposter : imposter_adj[v]){
        dfs(imposter, other_color);

        if(ans == -1)
            return;
    }
}

void solve(){
    cin>>n>>m;
    imposter_adj.assign(n+5, vector<int>());
    crewmate_adj.assign(n+5, vector<int>());

    for(int i = 1; i <= m; i++){
        int u, v; cin>>u>>v;
        string c; cin>>c;

        if(c == "imposter"){
            imposter_adj[u].push_back(v);
            imposter_adj[v].push_back(u);
        }
        else {
            crewmate_adj[v].push_back(u);
            crewmate_adj[u].push_back(v);
        }
    }

    ans = 0;
    color.assign(n+5, 0);

    for(int v = 1; v <= n; v++){
        if(color[v])
            continue;

        color1 = 0, color2 = 0;
        dfs(v);

        if(ans == -1)
            break;
        ans += max(color1, color2);
    }

    cout<<ans<<"\n";
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

