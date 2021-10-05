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

    ll consecutive_even = 0;
    bool odd_before = false;
    bool to_complete = false;

    ll ans = 0;

    cin>>n;
    for(int i = 0; i < n; i++){
        ll length; cin>>length;

        ans += length/2;

        const bool is_even = (length%2 == 0);
        if(is_even)
            consecutive_even++;
        else {
            if(odd_before and consecutive_even%2 == 0){
                ans++;
                odd_before = false;
            }
            else if(odd_before){
                if(to_complete){
                    ans++;
                    to_complete = false;
                }
                else
                    to_complete = true;
            }
            else
                odd_before = true;

            consecutive_even = 0;
        }
    }

    cout<<ans<<"\n";

}


int main(){
    cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

