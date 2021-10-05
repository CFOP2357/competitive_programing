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
    map<int, int> b_frecuency;

    cin>>n>>m;
    for(int i = 0; i < n; i++){
        ll z; cin>>z;
        a.push_back(z);
    }
    for(int i = 0; i < n; i++){
        ll z; cin>>z;
        b.push_back(z);

        b_frecuency[z]++;
    }

    int ans = INT_MAX;
    for(auto [number, frecuency] : b_frecuency){
        int x = (number+m - a[0]) % m;

        unordered_map<int, int> a_frecuency;
        for(int a_number : a)
            a_frecuency[(a_number+x)%m]++;

        bool is_ans = true;
        for(auto [number, frecuency] : b_frecuency)
            if(a_frecuency[number] != frecuency)
                is_ans = false;

        if(is_ans)
            ans = min(ans, x);
    }

    assert(ans != INT_MAX);
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

