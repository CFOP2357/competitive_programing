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

const ll MAX = 1000100; //10^6
const ll MOD = 1000000007;

/////////////////importado de KACTL/////////////////
// Fuente: https://github.com/kth-competitive-programming/kactl
// Pegar aqui cosas de katl necesarias



///////////////////////////////////////////////////

vector<ll> a;
vector<ll> b;
ll n, m;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    ll sum = 0;
    ll d;
    for(int i=0; i<n; i++){
        ll z; cin>>z;
        a.push_back(z);
        sum += z;
    }
    d = sum/n;

    for(auto &k : a){
        k = d-k;
        b.push_back(k);
    }
    reverse(all(b));

    ll current_cost = 0;
    ll cost = 0;
    int i = max_element(all(a))-a.begin();
    for(int j=0; j<3; j++){
        while(i<n){
            if(current_cost > 0)
                cost += current_cost;
            if(a[i]<0){
                ll k = min(abs(a[i]), current_cost);
                a[i] += k;
                current_cost-=k;
            }
            else {
                current_cost += a[i];
                a[i] = 0;
            }
            i++;
        }
        i=0;
    }

    ll ans = cost;

    current_cost = 0;
    cost = 0;
    i = max_element(all(b))-b.begin();
    for(int j=0; j<3; j++){
        while(i<n){
            if(current_cost > 0)
                cost += current_cost;
            if(b[i]<0){
                ll k = min(abs(b[i]), current_cost);
                b[i] += k;
                current_cost-=k;
            }
            else {
                current_cost += b[i];
                b[i] = 0;
            }
            i++;
        }
        i=0;
    }

    ans = min(cost, ans);
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

