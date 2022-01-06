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

struct Segment{
    int l;
    int r;
    ll c;
};

void solve(){
    cin>>n;

    Segment left_segment = {INT_MAX, 0, 0};
    Segment right_segment = {0, INT_MIN, 0};
    Segment middle_segment = {INT_MAX, INT_MIN, 0};
    for(int i = 0; i < n; i++){
        ll l, r, c;
        cin>>l>>r>>c;

        if(l < left_segment.l)
            left_segment = {l, r, c};
        if(r > right_segment.r)
            right_segment = {l, r, c};

        if(l == left_segment.l and c < left_segment.c)
            left_segment = {l, r, c};
        if(r == right_segment.r and c < right_segment.c)
            right_segment = {l, r, c};

        if(l < middle_segment.l and middle_segment.r < r
           or (l <= middle_segment.l and middle_segment.r < r)
           or (l < middle_segment.l and middle_segment.r <= r))
            middle_segment  = {l, r, c};
        if(l == middle_segment.l and middle_segment.r == r and c < middle_segment.c)
            middle_segment  = {l, r, c};

        if(middle_segment.l == left_segment.l and middle_segment.r == right_segment.r)
            cout<<min(middle_segment.c, left_segment.c + right_segment.c)<<"\n";
        else
            cout<<left_segment.c + right_segment.c<<"\n";
    }

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

