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

ll N, X;

int collition(int sx, int s, int d){
    if(s + d < sx){
        return 0;
    } else if (s < sx){
        d -= (sx - s);
        return 1 + d / X;
    } else {
        s -= sx;
        s %= X;
        d -= s;
        return 1 + d / X;
    }
}


void solve(){
    cin>>N>>X;
    unordered_map<ll, ll> coll;
    for(int i=0; i<N; i++){
        ll S, D; cin>>S>>D;
        for(ll j = 0; j<= 480; j++)
          coll[j] += collition(j, S, D);
    }

    ll ans = 0;
    for(ll j=1; j<=480; j++){
      if(coll[ans] > coll[j])
        ans = j;
    }

    cout<<ans<<" "<<coll[ans]<<"\n";
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

