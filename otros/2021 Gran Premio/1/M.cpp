
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

const int MAX = 1000100; //10^6
const int MOD = 1000000007;

/////////////////importado de KACTL/////////////////
// Fuente: https://github.com/kth-competitive-programming/kactl
// Pegar aqui cosas de katl necesarias



///////////////////////////////////////////////////

vector<ll> a;
vector<ll> b;
ll n, m, k, q;
string s;

bool is_on[360];

void solve(){
    a.clear(); b.clear();
    cin>>n;
    rep(i, 0, n){
        ll z; cin>>z;
        a.push_back(z);
        is_on[z] = true;
    }

    ll ans = 0;
    for(int d = 1; d <= 359; d++){
      for(int init = 0; init <= 359; init++){
        ll current = 0;
        unordered_map<int, bool> selected;
        for(int k = 0; k<=360; k+=d){
          if(selected[(init+k)%360] or not is_on[(init+k)%360])
            continue;
          if(not selected[(init+k+d)%360] and is_on[(init+k+d)%360]){
            current++;
            selected[(init+k+d)%360] = true;
            selected[(init+k)%360] = true;
          }
        }
        ans = max(current, ans);
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
