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
ll n, m;
string s;

bool possible(ll L){
    vector<ll> b(n, 0);

    for(int i = n-1; i >= 0; i--){
        if(a[i] + b[i] < L)
            return false;

        if(i > 1){
            ll d = min(a[i]/3, (a[i] + b[i] - L)/3);

            b[i-1] += d;
            b[i-2] += 2*d;
        }
    }

    return true;
}

//1111111111111111111110000000000
ll bs(ll l, ll r){ //[l, r)
    if(l+1 >= r)
        return l;

    ll m = (l + r)/2;

    if(possible(m))
        return bs(m, r);
    return bs(l, m);
}

void solve(){
    a.clear();

    cin>>n;
    for(int i = 0; i < n; i++){
        ll z; cin>>z;
        a.push_back(z);
    }

    cout<<bs(1, a.back()+1)<<"\n";

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

