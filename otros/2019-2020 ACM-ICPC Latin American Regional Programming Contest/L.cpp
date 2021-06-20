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

const int MAX = 2000; //10^6
const int MOD = 1000000007;

/////////////////importado de KACTL/////////////////
// Fuente: https://github.com/kth-competitive-programming/kactl
// Pegar aqui cosas de katl necesarias



///////////////////////////////////////////////////

vector<ll> a;
vector<ll> b;
ll n, m, k, q, x;
string s;
char grid[MAX][MAX];
ull dp[MAX][MAX];

void solve(){
    a.clear(); b.clear();
    cin>>n>>m;
    rep(i, 0, n){
        rep(j, 0, m)
            cin>>grid[i][j];
    }

    ull ans = 1;

    for(int j=0; j<m; j++)
        dp[0][j] = 1;

    for(int i=1; i<n; i++){
        dp[i][0] = 1;
        for(int j=1; j<m; j++){
            dp[i][j] = 1;
            if(grid[i-1][j]==grid[i-1][j-1] and grid[i][j]==grid[i][j-1])
                dp[i][j] = min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]})+1;
            ans = max(ans, dp[i][j]*dp[i][j]);
        }
    }


    cout<<ans<<"\n";
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


