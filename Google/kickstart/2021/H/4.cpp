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
typedef long long ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

const ll mod = MOD; // change to something else
struct Mod {
	ll x;
	Mod(ll xx) : x(xx) {}
	Mod operator+(Mod b) { return Mod((x + b.x) % mod); }
	Mod operator-(Mod b) { return Mod((x - b.x + mod) % mod); }
	Mod operator*(Mod b) { return Mod((x * b.x) % mod); }
	Mod operator/(Mod b) { return *this * invert(b); }
	Mod invert(Mod a) {
		ll x, y, g = euclid(a.x, mod, x, y);
		return Mod((x + mod) % mod);
	}
	Mod operator^(ll e) {
		if (!e) return Mod(1);
		Mod r = *this ^ (e / 2); r = r * r;
		return e&1 ? *this * r : r;
	}
};

vector<vector<int>> adj;
vector<Mod> a;
vector<Mod> b;

ull n, k, q;
string s;

ll u, v;
vector<Mod> ans;
vector<Mod> ans2;

Mod D(1000000);

bool u_child_of_v, v_child_of_u;
bool has_u, has_v;

void dfs(int node=1, int parent=-1){
    if(node == u){
        has_u = true;
        if(has_v)
            u_child_of_v = true;
    }
    if(node == v){
        has_v = true;
        if(has_u)
            v_child_of_u = true;
    }

    if(node != 1){
        if(parent == u or parent == v){
            ans[node] = a[node] * ans[parent];
        }
        else{
            ans[node] = a[node] * ans[parent];
            ans[node] = ans[node] + (b[node] * (Mod(1) - ans[parent]));
        }
    }
    for(auto child : adj[node])
        dfs(child, node);

    if(node == u)
        has_u = false;
    if(node == v)
        has_v = false;
}

void solve(){
    a.clear(); b.clear();
    adj.clear();

    u_child_of_v = false;
    v_child_of_u = false;

    a.push_back(0);
    b.push_back(0);

    cin>>n>>q;
    cin>>k;

    adj.assign(n+1, vector<int>());
    ans.assign(n+1, D);

    a.push_back(D);
    b.push_back(D);

    for(int u = 2; u <= n; u++){
        ll P, A, B;
        cin>>P>>A>>B;

        adj[P].push_back(u);
        a.push_back(Mod(A)/D);
        b.push_back(Mod(B)/D);
    }

    ans[1] = Mod(k)/D;
    while(q--){
        cin>>u>>v;

        dfs();

        if(not u_child_of_v and not v_child_of_u)
            cout<< (ans[u]*ans[v]).x <<" ";
        else if(u_child_of_v)
            cout<<ans[u].x<<" ";
        else
            cout<<ans[v].x<<" ";
    }
    cout<<"\n";
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


