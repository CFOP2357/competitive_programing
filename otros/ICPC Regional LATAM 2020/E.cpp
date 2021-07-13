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

typedef long long ull;
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

vector<pii> a; //val, pos
vector<ll> b;
ll n, m;
string s;
vector<ll> L, R;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    vector<ll> dp(n+1, -20);
    vector<ll> L(n, -1);
    vector<ll> R(n, -1);
    for(int i=0; i<n; i++){
        ll z; cin>>z;
        a.push_back({z, i});
        b.push_back(z);
    }
    sort(all(a), greater<pii>());

    set<ll, greater<ll>> pos_left;
    set<ll> pos_right;

   /* for(int i=0; i<n; i++){
        cout<<i<<"  ";
    }cout<<"\n";*/

    bool gg = false;
    for(auto p : a){
        ll pos = p.second;
        if(gg){

            ll l, r;
            if(pos_left.lower_bound(pos) == pos_left.end())
                l = n;
            else
                l = *pos_left.lower_bound(pos);

            if(pos_right.lower_bound(pos) == pos_right.end())
                r = n;
            else
                r = *pos_right.lower_bound(pos);

            //cout<<pos<<" "<<l<<" "<<r<<"\n";

            L[pos] = l;
            R[pos] = r;

            if(r == n or l==n){
                dp[pos] = max({dp[pos], dp[l]+1, dp[r]+1});
                pos_left.insert(pos);
                pos_right.insert(pos);
                continue;
            }

            if(abs(pos-l) == abs(pos-r)){
                if(b[l]>b[r]){
                    r = R[l];
                }
                else{
                    l = L[r];
                }
            }
            else if(abs(pos-l) < abs(pos-r)){
                if(b[l] > b[r])
                    r = R[l];
            }
            else {
                if(b[r] > b[l])
                    l = L[r];
            }

            dp[pos] = max({dp[pos], dp[l]+1, dp[r]+1});

        }
        else {
            gg = true;
            dp[pos] = 0;
            L[pos] = R[pos] = n;
        }

        pos_left.insert(pos);
        pos_right.insert(pos);
    }

    for(int i = 0; i<n-1; i++)
        cout<<dp[i]<<" ";
    cout<<dp[n-1]<<"\n";

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
/*
8
84 83 82 81 80 75 70 90

10
2 9 7 4 6 10 1 8 3 5
ans = 2 1 2 3 1  0 1 1 2 2

10
100 3 2 80 10 1 90 91 92 93
*/
