/*
3

0 0 25 10
10 25 15 0
5 15 10 10


3
10 25 15  0
0   0 25 10
5  15 10 10

10 - 35 - 50 - 0
0 -  0 -  75 - 85
15 - 30 - 85 - 95

10 -35 - 50 - 50
0 -  0 - 25 - 35
5 - 20 - 30 - 20
15

0 - # - # - # - #
0 - 0 - # - # - #
0 - # - # - # - #
# - # - # - # - #

# - # - # - # - #
# - # - # - # - #
# - # - # - # - #
# - # - # - # - #


# - # - # - # - #
# - # - # - # - #
# - # - # - # - #
# - # - # - # - #
10 - 35 - 50
10 - 35 - 60
15 - 40 - 70

*/
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

const int MAX = 1e5 +100;
const int MOD = 1000000007;

/////////////////importado de KACTL/////////////////
// Fuente: https://github.com/kth-competitive-programming/kactl
// Pegar aqui cosas de katl necesarias



///////////////////////////////////////////////////

vector<ll> a;
vector<ll> b;
ll n, m, k, q;
string s;
ull input[MAX][5];
ull ans[MAX][5];

void solve(){

  cin>>n;

  queue<int> nxt[5];
  ull time[5] = {0,0,0,0,0};

  for(int i = 1; i<=n; i++)
    for(int j = 1; j<=4; j++)
      cin>>input[i][j];

  for(int i = 1; i<=n; i++){
    int j = 1;
    for(j = 1; j<=4; j++)
      if(input[i][j])
        break;

    nxt[j].push(i);
  }

  bool p = true;
  while(p){
    p = false;
    for(int j = 1; j<=4; j++){
      if(nxt[j].size()){
        p = true;

        int i = nxt[j].front();
        nxt[j].pop();

        ans[i][j] = ans[i][j-1];
        ans[i][j] = max(ans[i][j], time[j]);

        ans[i][j] += input[i][j];
        time[j] = ans[i][j];

        if(j < 4)
          nxt[j+1].push(i);
      }
    }
  }

  cout<<*max_element(all(time))<<"\n";
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
