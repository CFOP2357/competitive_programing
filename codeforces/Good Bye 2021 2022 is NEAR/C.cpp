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

typedef long double ld;

#define MAX 1000100
#define MOD 1000000007

vector<ld> a;
ll n, m;
string s;

void solve(){
    a.clear();

    cin>>n;
    for(int i = 0; i < n; i++){
        ld z; cin>>z;
        a.push_back(z);
    }

    ll ans = n-1;

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++){
            ll current_ans = 0;
            for(int k = 0; k < n; k++){
                if((a[j]-a[i]) * (k-i) != (a[k]-a[i]) * (j-i))
                    current_ans++;
            }

            ans = min(ans, current_ans);
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

