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
ll n, m, k;
string s;

void add_string(string &s, string to_add){
    reverse(all(to_add));
    for(char character : to_add)
        s.push_back(character);
}

void solve(){
    a.clear();
    cin>>n>>k;

    for(int i = 0; i < n; i++){
        ll z; cin>>z;
        a.push_back(z);
    }

    string ans = "";
    for(int i = 0; i < n and k >= 0; i++){
        if(i == n-1)
            add_string(ans, to_string(k+1));
        else {
            ll to_add = 0;
            for(int j = a[i]; j < a[i+1]; j++){
                to_add *= 10LL;
                to_add += 9LL;
            }
            to_add = min(to_add, k+1);

            k -= to_add;

            add_string(ans, to_string(to_add));
        }
    }

    reverse(all(ans));
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

