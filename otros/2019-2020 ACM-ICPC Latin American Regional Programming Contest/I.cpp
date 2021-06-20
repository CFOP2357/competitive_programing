//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>

#include <map>
#include <set>

#include <stack>
#include <queue>

#include <unordered_map>
#include <unordered_set>

#include <cmath>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

const int MAX = 3000; //10^6
const int MOD = 1000000007;

/////////////////importado de KACTL/////////////////
// Fuente: https://github.com/kth-competitive-programming/kactl
// Pegar aqui cosas de katl necesarias



///////////////////////////////////////////////////

vector<vector<ll>> M;
ll N, L;
string s;

ull ans[MAX];
set<ull> clients;

ull solve_pos(ull i){
    if(ans[i])
        return ans[i];
    if(i > L){
        clients.insert(i);
        return ans[i] = 1;
    }
    for(auto m : M[i]){
        ans[i] += solve_pos(m);
        ans[i] %= MOD;
    }
    return ans[i];
}

void solve(){
    M.push_back(vector<ll>());
    cin>>N>>L;
    rep(i, 0, L){
        ll k; cin>>k;
        M.push_back(vector<ll>());
        while(k--){
            ull m; cin>>m;
            M.back().push_back(m);
        }
    }

    cout<<solve_pos(1)<<" "<<clients.size()<<"\n";
}


int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    // revisa que el input tenga sentido,
    // si no arroja el error cin.failbit
    cin.exceptions(cin.failbit);

    //srand (time(nullptr));

    int t=1; //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

