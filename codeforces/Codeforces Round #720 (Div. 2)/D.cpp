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

#define MAX 100010
#define MOD 1000000007

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

ull n, m;
string s;

vector<int> adj[MAX];
vector<vector<int>> ans;
int a, b;
int B;
int L[MAX];
UF uf(1);

void find_fartest(int &fartest, int &max_d, int current, int parent = -1, int d = 1){
    if(d > max_d){
        fartest = current;
        max_d = d;
    }

    for(auto child : adj[current]){
        if(child == parent)
            continue;
        find_fartest(fartest, max_d, child, current, d+1);
    }
}

int leaf;
int paths = 0;
vector<bool> isOk;
void make_bamboo(int current, int parent=-1){
    //cout<<current<<"\n";

    if(adj[current].size()>2)
        paths += (adj[current].size()-2);

    for(auto child : adj[current]){
        if(child == parent)
            continue;

        make_bamboo(child, current);
        if(uf.find(child)!=uf.find(current)){
            ans.push_back({current, child, L[uf.find(current)], child});
            int d = L[uf.find(child)];
            uf.join(child, current);
            L[uf.find(child)] = d;
        }
    }
}


int dfs2(int current, int parent=-1){
    if(adj[current].size()==1 && parent!=-1){
        L[current] = current;
        return current;
    }

    int resp = false;
    for(auto child : adj[current]){
        if(child == parent)
            continue;
        resp = dfs2(child, current);
    }

    L[current] = resp;
    uf.join(current, resp);
    return resp;
}

void solve(){
    a=1, b=1;
    ans.clear();
    cin>>n;
    for(int i=1; i<=n; i++){
        adj[i].clear();
    }
    for(int i=1; i<n; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int max_d = 0;
    find_fartest(a, max_d, 1);
    max_d = 0;
    find_fartest(b, max_d, a);

    isOk.assign(n+1, false);

    uf = UF(n+1);

    leaf = b;
    dfs2(a);

    leaf=b;
    make_bamboo(b);

    cout<<paths<<"$\n";

    cout<<ans.size()<<"\n";
    for(auto a : ans){
        for(auto k : a)
            cout<<k<<" ";
        cout<<"\n";
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
/*
1
7
1 2
1 3
2 4
2 5
3 6
3 7

1
38
7 36
13 5
16 27
4 22
6 38
37 5
20 1
30 1
24 19
11 5
33 1
27 31
10 30
23 34
1 6
19 1
1 21
1 3
20 25
30 22
16 14
32 30
33 28
19 2
9 14
36 23
1 14
12 8
23 35
16 8
1 5
20 17
26 30
29 19
30 23
15 6
18 30

1
4
1 2
2 3
2 4

1
12
1 2
2 3
2 4
4 5
4 6
6 7
7 5
7 8
6 9
9 10
9 11
*/

