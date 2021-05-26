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

ull n, k, m, w;
string s;

ull ans;
vector<vector<int>> children_of;
vector<int> parent_of;
vector<ull> skill;
vector<ull> max_dist;

priority_queue<pii> nxt; //dist, node
ull dfs(int current=0){
  max_dist[current] = 1;
  for(auto child : children_of[current]){
    max_dist[current] = max(dfs(child), max_dist[current]);
  }
  max_dist[current];
  return max_dist[current]+1;
}

void construct_path(int current){
  int child_on_path;

  if(!children_of[current].size()){ //is_leaf
    return;
  }

  for(auto child : children_of[current]){
    if(max_dist[current]-1 == max_dist[child])
      child_on_path = child;
  }
  for(auto child : children_of[current]){
    if(child != child_on_path)
       nxt.push({max_dist[child], child});
  }

  construct_path(child_on_path);
}

void solve(){

    cin >> n >> k;

    skill.resize(k);
    max_dist.assign(n, 0);

    for(int i = 0; i < k; i++){
        cin >> skill[i];
    }
    sort(all(skill));

    parent_of.resize(n);
    children_of.resize(n);

    for(int i = 1; i < n; i++){
        cin >> parent_of[i];
        children_of[parent_of[i]].push_back(i);
    }

    dfs();

    /*for(auto x : max_dist)
      cout<<x<<" ";
    cout<<"\n";*/

    for(auto child : children_of[0])
      nxt.push({max_dist[child], child});

    while(nxt.size() && skill.size()){
      int current = nxt.top().second;
      ull dist = nxt.top().first;
      nxt.pop();
      ans += skill.back()*dist;
      skill.pop_back();
      construct_path(current);
    }
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

