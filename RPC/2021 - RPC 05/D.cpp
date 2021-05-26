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

#define MAX 200010
#define MOD 1000000007

ull n, m, w;
string s;

ull ans;
vector<int> adj[MAX];
vector<ull> lack, already;

void dfs(int current, ull to_fill){
  to_fill = max(lack[current], to_fill-already[current]);
  ans = min(ans, to_fill);

  for(auto child : adj[current])
    dfs(child, to_fill);
}

void solve(){
  cin>>n>>w;
  lack.assign(n+1, 0);
  already.assign(n+1, 0);
  ans = w;
  for(int i=1; i<=n; i++){
    ull d, c, u;
    cin>>d>>c>>u;
    adj[d].push_back(i);
    lack[i] = c-u;
    already[i] = u;
  }

  dfs(0, w);

  cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

