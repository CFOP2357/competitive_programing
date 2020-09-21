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

#define MAX 200100
#define MOD 1000000007

vector<int> adj[MAX];
ull n, m;

vector<int> ans;
vector<int> ans2;
vector<int> ANS;
int color[MAX];

void dfs(int v, int c = 1){
    if(color[v])
        return;
    color[v] = c;

    if(c==1) ans.push_back(v);
    else ans2.push_back(v);

    for(int u : adj[v])
        dfs(u, c==1?2:1);

}

int p[MAX];

void solve(){
    ans.clear(); ans2.clear(); ANS.clear();
    cin>>n>>m;
    fill(adj, adj+n+5, vector<int>());
    fill(color, color+n+5, 0);
    fill(p, p+n+5, 0);

    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        p[b]++;
    }

    for(int i=1; i<=n; i++){
        if(!color[i]){
                dfs(i);
                if(ans.size()>ans2.size()) for(int k:ans2) ANS.push_back(k);
                else for(int k:ans) ANS.push_back(k);
                ans.clear(); ans2.clear();
        }
    }



    cout<<ANS.size()<<"\n";
    for(int a : ANS)
        cout<<a<<" ";
    cout<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

