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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

ll a, b, c, m;

void solve(){
    cin>>a>>b>>c>>m;
    ll n = a + b + c;

    ll max_m = a-1 + b-1 + c-1;
    ll min_m = 0;

    ll max_letter = max({a, b, c});
    if(max_letter > (n+1)/2){
        max_letter -= (n+1)/2;

        if(n%2 == 0){
            min_m++;
            max_letter--;
        }

        min_m += max_letter*2;
    }

    if(min_m <= m and m <= max_m)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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

