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
    cin>>n;

    map<ll, ll> a_frecuency;
    map<ll, ll> b_frecuency;

    map<ll, vector<ll>> from_a;
    map<ll, vector<ll>> from_b;

    for(int i = 0; i < n; i++){
        ll ai, bi; cin>>ai>>bi;
        a.push_back(ai);
        b.push_back(bi);

        a_frecuency[ai]++;
        b_frecuency[bi]++;

        from_a[ai].push_back(bi);
        from_b[bi].push_back(ai);
    }


    ll ans = (n * (n-1) * (n-2)) / 6LL;

    for(const auto &[ai, elements] : from_a){
        for(auto bi : elements){
            b_frecuency[bi]--;

            ans -= b_frecuency[bi]*(a_frecuency[ai]-1);
        }
    }


    cout<<ans<<"\n";
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

/*
4
4
1 2
2 1
1 1
4 4
3
1 1
1 2
1 3
3
1 1
2 2
3 3
3
1 1
1 2
2 2

1
3
1 1
1 2
1 3
*/

