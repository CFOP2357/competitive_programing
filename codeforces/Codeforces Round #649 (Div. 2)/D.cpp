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

#define MAX 100100
#define MOD 1000000007

vector<int> adj[MAX];
ull n, m, k;

vector<ull> a;
vector<ull> b;
bool visited[MAX];
int pos[MAX];

vector<int> ans;

int dfs(int v, int p = -1, bool c = true){

    //cout<<v<<"$\n";

    visited[v] = true;

    if(c)
        a.push_back(v);
    else b.push_back(v);

    int nxt = 0;
    for(int u : adj[v]){
        if(p==u) continue;

        if(visited[u]){
            //cout<<"^"<<u<<"\n";
            if(pos[u] > pos[nxt])
                nxt = u;
        }

    }

    if(nxt){
        ans.push_back(v);
        return nxt;
    }

    for(int u : adj[v]){
        if(p==u) continue;

        pos[u] = pos[v]+1;

        int r = dfs(u, v, !c);
        if(r){
            //cout<<v<<" "<<r<<"#\n";
            ans.push_back(v);
            if(r==v){

                /*for(int i=0; i<=n; i++)cout<<pos[i]<<" ";
                cout<<"\n";*/
                if(ans.size()<=k){
                    cout<<2<<"\n";
                    cout<<ans.size()<<"\n";
                    for(int a: ans) cout<<a<<" ";
                    cout<<"\n";
                }
                else {
                   if(k%2) k+=2;
                   k/=2;
                   cout<<"1\n";
                   for(int i=0, j=0; j<k; i+=2, j++)
                     cout<<ans[i]<<" ";
                }
                exit(0);
            }
            return r;
        }
    }

    return 0;
}

void solve(){
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pos[0] = -1;
    dfs(1);

    if(k%2) k+=2;
    k/=2;

    if(a.size()<b.size())swap(a, b);

    cout<<"1\n";
    for(int i=0; i<k; i++)
        cout<<a[i]<<" ";

}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

/*
4 5 3
1 2
2 3
3 4
4 1
2 4

4 6 3
1 2
2 3
3 4
4 1
1 3
2 4
*/
