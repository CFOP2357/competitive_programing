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


#define MAX 1050
#define MOD 1000000007

vector<ll> a;
vector<ll> b;
ll n, m;
string s;


char grid[MAX][MAX];

ll solution[MAX][MAX];

ll dfs(int row, int column, char c){
    if(grid[row][column] != c)
        return 0;
    if(solution[row][column])
        return solution[row][column];

    grid[row][column] = '.';

    ll ans = 0;

     ans = max(ans, dfs(row, column+1, c+1));
     ans = max(ans, dfs(row, column-1, c+1));
     ans = max(ans, dfs(row+1, column+1, c+1));
     ans = max(ans, dfs(row-1, column+1, c+1));
     ans = max(ans, dfs(row+1, column-1, c+1));
     ans = max(ans, dfs(row-1, column-1, c+1));
     ans = max(ans, dfs(row+1, column, c+1));
     ans = max(ans, dfs(row-1, column, c+1));

    ans++;

    grid[row][column] = c;

    return solution[row][column] = ans;
}

void solve(){
    cin>>n>>m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin>>grid[i][j];
        }

    ll ans = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(grid[i][j] != '.'){
                ans = max(dfs(i, j, grid[i][j]), ans);
            }
        }

    cout<<ans<<"\n";
}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

