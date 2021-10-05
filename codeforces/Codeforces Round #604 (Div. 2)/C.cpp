//#include <bits/stdc++.h>
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

#include <assert.h>

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
typedef int64_t ll;
typedef uint64_t ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

vector<ll> a;
vector<ll> b;
ll n, m;
string s;

void solve(){
    a.clear(); b.clear();

    ll last_p = -1;
    cin>>n;
    for(int i = 0; i < n; i++){
        ll z; cin>>z;

        if(z == last_p)
            a.back()++;
        else
            a.push_back(1);

        last_p = z;
    }

    ll ans_g, ans_s, ans_b;
    ans_g = ans_s = ans_b = 0;


    if(a.size() < 3){
        cout<<"0 0 0\n";
        return;
    }

    ll g(a[0]), s(a[1]), b(a[2]);
    int g_idx(0), s_idx(1), b_idx(2);
    while(g+s+b <= n/2){
        if(g > 0 and s > 0 and b > 0 and g < s and g < b){
            ans_g = g;
            ans_b = b;
            ans_s = s;
        }

        if(g >= s or s <= 0){
            s_idx += 1;
            s += a[s_idx];
            b -= a[s_idx];
        }
        else{
            b_idx += 1;
            b += a[b_idx];
        }
    }

    cout<<ans_g<<" "<<ans_s<<" "<<ans_b<<"\n";

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

