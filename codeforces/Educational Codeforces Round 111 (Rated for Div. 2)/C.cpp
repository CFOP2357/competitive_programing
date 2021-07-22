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

vector<ll> a;
vector<ll> b;
ll n, m;
string s;

bool isGood(vector<int> c){
    if(c[0]<c[1] and c[1]>c[2])
        return true;
    if(c[0]>c[1] and c[1]<c[2])
        return true;
    return false;
}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ll z; cin>>z;
        a.push_back(z);
    }

    ll ans = 2*n-1;
    for(int i=2; i<n; i++){
        if(isGood({a[i-2], a[i-1], a[i]}))
            ans++;
    }

    for(int i=3; i<n; i++){
        if(isGood({a[i-3], a[i-2], a[i-1]})
           and isGood({a[i-3], a[i-2], a[i]})
           and isGood({a[i-3], a[i-1], a[i]})
           and isGood({a[i-2], a[i-1], a[i]}))
            ans++;
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

