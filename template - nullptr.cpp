#include <bits/stdc++.h>
#include <cassert>

//#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using ll = int64_t;
using ull = uint64_t;
using ld = long double;
using pii = pair<ll, ll>;
using vi = vector<ll>;

#define MAX 1000100
#define MOD 1000000007


/////////// THIRD PARTY CODE ///////////

///////////////////////////////////////

vector<ll> a;
vector<ll> b;
ll n, m, k;
string s;

void solve(){
    ll ans = 0;
    for(ll i = 1; i <= 50; i++){
        ans += pow(i, 5);
        cout<<ans<<"\n";
    }

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1; //cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

