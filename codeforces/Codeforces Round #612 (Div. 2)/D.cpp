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

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 2050
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

vector<int> adjTree[MAX];
vector<int> adj[MAX];

ull C[MAX];
ull currentC[MAX];
ull ord[MAX];
bool visited[MAX];

int root = 0;

vector<int> last;

void dfs2(int v, int current, int p){

    if(C[current]+1 <= currentC[v]){
        currentC[v] --;
        adj[v].push_back(current);
        //return;
    }
    else
        adj[current].push_back(v);

    for(int u : adjTree[current]){

        if(u!=p){
            dfs2(v, u, current);
        }

    }

}

ull dfs(int v, int p = 0){

    for(int u : adjTree[v]){
        if(p!=u)
            dfs2(v, u, p);
    }

    ull ans = 0;
    for(int u : adjTree[v]){
        if(p!=u)
            ans += dfs(u, p);
    }

    if(C[v] > ans){
        cout<<"NO\n";
        exit(0);
    }

    return ans+1;
}


int kk = 0;
void topOrder(int v){
    if(visited[v])
        return;
    visited[v] = true;

    for(int u : adj[v])
        topOrder(u);

    ord[v] = ++kk;
}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=1; i<=n; i++){
        ull p, c; cin>>p>>c;

        if(!p)
            root = i;
        else
            adjTree[p].push_back(i);

        C[i] = currentC[i] = c;
    }

    last.push_back(0);
    dfs(root);

    for(int i=1; i<=n; i++)
        if(!visited[i])
            topOrder(i);

    cout<<"YES\n";
    for(int i=1; i<=n; i++)
        cout<<ord[i]<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

