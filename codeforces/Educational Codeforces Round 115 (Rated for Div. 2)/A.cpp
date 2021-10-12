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

ll n, m;
string s[2];

void solve(){
    cin>>n;
    cin>>s[0];
    cin>>s[1];

    if(s[0][0] == '1'){
        cout<<"NO\n";
        return;
    }

    for(int i = 0; i < n; i++){
        if(s[0][i] == '1' and s[1][i] == '1'){
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
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

