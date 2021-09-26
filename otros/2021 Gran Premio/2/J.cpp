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
    ll A, T;
    cin>>A>>T;

    vector<ll> dp(T+1, 0);
    vector<vector<pii>> next_to(T+1, vector<pii>()); //length, happines

    while(A--){
        ll h, d, t; cin>>h>>d>>t;

        while(t--){
            int start_time; cin>>start_time;
            next_to[start_time].push_back({d, h});
        }
    }

    for(int i = 0; i <= T; i++){
        if(i)
            dp[i] = max(dp[i], dp[i-1]);

        for(auto [d, h] : next_to[i])
            dp[min(i + d, T)] = max(dp[min(i + d, T)], h + dp[i]);
    }

    cout<<dp.back()<<"\n";
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

