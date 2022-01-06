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

vector<ll> a;
vector<ll> b;
ll n, m;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    vector<vector<ll>> grid(2*n, vector<ll>(2*n, 0));
    for(int row = 0; row < 2*n; row++)
        for(int column = 0; column < 2*n; column++)
            cin>>grid[row][column];

    ll ans = 0;
    for(int row = n; row < 2*n; row++)
        for(int column = n; column < 2*n; column++)
            ans += grid[row][column];

    ans += min({
               grid[n][n-1],
               grid[n-1][n],
               grid[2*n-1][n-1],
               grid[n-1][2*n-1],
               grid[0][n],
               grid[0][2*n-1],
               grid[n][0],
               grid[2*n-1][0]}
              );

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

