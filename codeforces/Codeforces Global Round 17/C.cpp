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

bool possible(ll inv){
    ll min_a = inv - 1;
    ll min_b = 0;

    for(int i = 0; i < n; i++){
        if(a[i] >= min_a and b[i] >= min_b){
            min_a--;
            min_b++;

            inv--;
        }
    }

    if(inv <= 0)
        return true;
    return false;
}

ll bs(ll l, ll r){ //[1, r)
    if(l+1 >= r)
        return l;

    ll m = (l+r)/2;
    if(possible(m))
        return bs(m, r);
    return bs(l, m);
}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i = 0; i < n; i++){
        ll A, B; cin>>A>>B;
        a.push_back(A);
        b.push_back(B);
    }

    cout<<bs(1, n+1)<<"\n";
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

