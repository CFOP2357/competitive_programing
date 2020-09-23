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

vector<ull> a;
vector<ull> b;
bool visited[MAX];
int r[MAX];
int T[MAX];
vector<int> adj[MAX];
ull n, m, k;
vector<int> ans;

void dfs1(int v, bool c = true){
    if(visited[v])
        return;
    visited[v] = true;

    if(c)
        a.push_back(v);
    else b.push_back(v);

    for(int u : adj[v])
       dfs1(u, !c);
}

int dfs(int v, int d = 1, int anc = -1){

    cout<<v<<" "<<d<<" "<<r[v]<<"\n";

    if(visited[v]){
        cout<<"#\n";
        if(r[v] && d-r[v]+1 <= k){
            return d-r[v]+1;
        }
        return 0;
    }
    visited[v] = true;

    r[v] = d;
    for(int u : adj[v]){

        if(u==anc) continue;

        int p = dfs(u, d+1, v);
        if(p){
            if(p<0) return -1;
            ans.push_back(v);
            p--;
            if(p==0) p=-1;
            return p;
        }

    }

    r[v] = 0;

    return 0;
}



void solve(){
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1);

    int p = k;
    if(p%2) p+=2;
    p/=2;

    /*if(a.size()>=p){
        cout<<"1\n";
        for(int i=0; i<p; i++)
            cout<<a[i]<<" ";
        return;
    }

    if(b.size()>=p){
        cout<<"1\n";
        for(int i=0; i<p; i++)
            cout<<b[i]<<" ";
        return;
    }*/


    fill(visited, visited+n+5, false);

    queue<pii> nxt; //time, v
    queue<int> P; //dad
    nxt.push({1, 1});
    P.push(-1);

    while(nxt.size()){
        int v = nxt.front().second, t=nxt.front().first;
        nxt.pop();
        int p = P.front(); P.pop();

        T[v] = t;
        visited[v] = true;

        for(int u : adj[u]){
            if(u==p) continue;

            if(visited[u]){
                if(T[u] + T[v] <= k){

                    if(T[u]<T[v]) swap(u, v);

                    vector<int> ans2;
                    while(T[u]>T[v]){
                        ans.push_back(u);
                        for(int a : adj[u]){
                            if(T[a]==T[u]-1){
                                u=a;
                                break;
                            }
                        }
                        return;
                    }


                    while(u!=v){
                        ans.push_back(u);
                        ans2.push_back(v);

                        for(int a : adj[v]){
                            if(T[a]==T[v]-1){
                                v=a;
                                break;
                            }
                        }

                        for(int a : adj[u]){
                            if(T[a]==T[u]-1){
                                u=a;
                                break;
                            }
                        }

                    }

                    cout<<"2\n";
                    cout<<ans.size()+ans2.size()<<"\n";
                    for(int a : ans)
                        cout<<a<<" ";
                    reverse(all(ans2));
                    for(int a : ans2)
                        cout<<a<<" ";
                    cout<<"\n";

                    return;
                }
            }
            else {
                nxt.push({t+1, u});
                P.push(v);
            }

        }
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

