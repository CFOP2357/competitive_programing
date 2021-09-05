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

void solve(){
    a.clear(); b.clear();
    cin>>n;
    ll even = 0, odd = 0;
    vector<int> odd_pos, even_pos;
    for(int i = 0; i < n; i++){
        ll z; cin>>z;
        a.push_back(z);

        if(z%2){
            odd++;
            odd_pos.push_back(i);
        }
        else{
            even++;
            even_pos.push_back(i);
        }
    }

    if(odd != even and odd+1 != even and even+1 != odd){
        cout<<"-1\n";
        return;
    }

    ll ans = LLONG_MAX;

    if(even == odd or even == odd+1){
        ll current_ans = 0;
        for(int i = 0, j = 0; j < even; j++, i+=2)
            current_ans += abs(even_pos[j]-i);
        ans = min(current_ans, ans);
    }

    if(even == odd or even+1 == odd){
        ll current_ans = 0;
        for(int i = 0, j = 0; j < odd; j++, i+=2)
            current_ans += abs(odd_pos[j]-i);
        ans = min(current_ans, ans);
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

