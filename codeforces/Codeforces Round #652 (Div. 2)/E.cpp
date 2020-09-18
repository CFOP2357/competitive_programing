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

typedef long long ull;
typedef pair<ull, ull> pii;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define MAX 200100
#define MOD 1000000007

int n, m;
int w[MAX];

vector<int> adj[MAX];
vector<int> id[MAX];
int nb[MAX];
bool selected[MAX];

vector<int> ans;

void solve(){
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>w[i];

    for(int i=1; i<=m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        id[a].push_back(i);
        id[b].push_back(i);
        nb[a]++; nb[b]++;
    }

    queue<int> nxt;
    for(int i = 1; i <= n; i++)
        if(w[i] >= nb[i])
            nxt.push(i);

    while(nxt.size()){
        int v = nxt.front(); nxt.pop();

        for(int i = 0; i<adj[v].size(); i++){
            int u = adj[v][i], id = ::id[v][i];

            if(!selected[id]){
                ans.push_back(id);
                selected[id] = true;

                nb[v]--;
                nb[u]--;

                if(nb[u]<=w[u])
                    nxt.push(u);

            }

        }

    }

    //print
    if(ans.size() == m){
        cout<<"ALIVE\n";
        reverse(ans.begin(), ans.end());
        for(int a : ans)
            cout<<a<<" ";
        cout<<"\n";
    }
    else cout<<"DEAD";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}

