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

map<ll, bool> a;
map<ll, bool> b;
map<ll, bool> c;
ll k1,k2,k3;
ll n;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>k1>>k2>>k3;
    n = k1+k2+k3;
    for(int i=0; i<k1; i++){
        ll z; cin>>z;
        a[z]=true;
    }
    for(int i=0; i<k2; i++){
        ll z; cin>>z;
        b[z]=true;
    }
    for(int i=0; i<k3; i++){
        ll z; cin>>z;
        c[z]=true;
    }

    vector<ll> cost(n+2, 0);
    ll current_cost = b.size();
    cost[0] = current_cost;
    for(int i=1; i<=n; i++){
        if(b[i])
            current_cost--;
        if(c[i])
            current_cost++;
        cost[i] = current_cost;
    }
    cost[n+1] = c.size();
    ll ans = *min_element(all(cost));

    current_cost = a.size();
    for(int i=0; i<=n+1; i++){
        if(a[i])
            current_cost--;
        else
            current_cost++;
        ans = min(current_cost+cost[i], ans);
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

