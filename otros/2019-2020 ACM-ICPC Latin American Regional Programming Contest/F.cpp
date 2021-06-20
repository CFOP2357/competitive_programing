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

const int MAX = 10; //10^6
const int MOD = 1000000007;

/////////////////importado de KACTL/////////////////
// Fuente: https://github.com/kth-competitive-programming/kactl
// Pegar aqui cosas de katl necesarias



///////////////////////////////////////////////////

vector<ll> a;
vector<ll> b;
ll n, m, k, q, x;
string s;

ull dp[MAX][MAX];

void solve(){
    for(int i=1; i<MAX; i++)
        dp[i][i] = dp[1][i] = 1;


    for(ull j=2; j<MAX; j++){
        for(ull i=2; i<MAX; i++){
            if(j>i){
                ull d = j-i;
                ull ans = 0;
                for(int k=1; k<=min(d, i); k++){
                    ans += dp[k][d]*(i-k+1);
                    ans %= MOD;
                }
                dp[i][j] = ans;
            }
        }
    }

    /*ull S, B; cin>>S>>B;
    cout<<dp[S][B]<<"\n";*/

    for(int i=1; i<MAX; i++){
        for(int j=1; j<MAX; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

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

