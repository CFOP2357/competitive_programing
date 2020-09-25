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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m;

bool grid[50][50];
map<int, int> one;
map<int, int> zero;
bool v[50][50];

void solve(){
    one.clear(); zero.clear();
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) cin>>grid[i][j];
        fill(v[i], v[i]+m+5, false);
    }

    queue<pair<int, pii>> nxt; //time, pos {y, x}
    nxt.push({1, {0, 0}});
    nxt.push({1, {n-1, m-1}});

    int max_t = 0;

    while(nxt.size()){
        int y = nxt.front().second.first, x = nxt.front().second.second;
        int t = nxt.front().first;
        nxt.pop();

        if(y>=n || y<0 || x>=m || x<0) continue;
        if(v[y][x]) continue;
        v[y][x] = true;

        zero[t] += !grid[y][x];
        one[t] += grid[y][x];

        max_t = max(max_t, t);

        nxt.push({t+1, {y+1, x}});
        nxt.push({t+1, {y-1, x}});
        nxt.push({t+1, {y, x+1}});
        nxt.push({t+1, {y, x-1}});

    }

    max_t -= (n%2 == m%2);

    int ans = 0;
    for(int i=1; i<=max_t; i++)
        ans += min(zero[i], one[i]);

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

