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

#define MAX 1005
#define MOD 1000000007

vector <int> adj[MAX]; //adj[i]=j, i->j
ull n;

vector<int> order[MAX];

int sz = 0;

bool visited[MAX];
void topSort(int v = 0, int level = 0){
  if(visited[v])
    return;
  visited[v] = true;

  sz++;

  for(int u : adj[v])
    topSort(u, level+1);

  order[level].push_back(v);
}


vector<string> grid;
void solve(){

  cin>>n;
  for(int i = 0; i < n; i++){
    string s; cin>>s;
    grid.push_back(s);
    for(int j = 0; j < n; j++){
      if(i!=j && s[j] == '0'){
        adj[i].push_back(j);
      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if( i!=j && (grid[i][j]==grid[j][i] && grid[i][j]!='X') ){
        cout<<"impossible\n";
        return;
      }
    }
  }

  topSort();

  if(sz != n){
    cout<<"impossible\n";
    return;
  }

  for(int i=MAX-1; i>0; i--)
    for(int ans : order[i])
      cout<<ans<<" ";
  cout<<"0\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

/*
6
X01011
1X1001
01X000
111X00
0111X0
00111X
*/
