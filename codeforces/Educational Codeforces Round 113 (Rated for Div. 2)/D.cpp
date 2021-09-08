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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;

#define findBO find_by_order
#define findBK order_of_key


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()


#define MAX 1000100
#define MOD 1000000007

ll n, m, k;
string s;

void solve(){
    cin>>n>>m>>k;

    orderedSet vertical;
    orderedSet horizontal;

    set<int> verticalSet;
    set<int> horizontalSet;

    unordered_map<ll, bool> is_vertical_line;
    unordered_map<ll, bool> is_horizontal_line;
    for(int i = 0; i < n; i++){
        ll x; cin>>x;
        vertical.insert(x);
        verticalSet.insert(x);

        is_vertical_line[x] = true;
    }
    for(int i = 0; i < m; i++){
        ll y; cin>>y;
        horizontal.insert(y);
        horizontalSet.insert(y);

        is_horizontal_line[y] = true;
    }

    vector<orderedSet> vertical_pos(n+1, orderedSet());
    vector<orderedSet> horizontal_pos(m+1, orderedSet());

    orderedSet X;
    orderedSet Y;

    ll ans = 0;
    while(k--){
        ll x, y; cin>>x>>y;

        if(is_vertical_line[x] and is_horizontal_line[y]) //no es parte de ningun par
            continue;

        if(not is_vertical_line[x]){ //esta en una linea horizontal
            if(not verticalSet.size()){
                X.insert(x);
                Y.insert(y);
                continue;
            }

            auto right_line = verticalSet.lower_bound(x);

            auto left_line = right_line;
            if(left_line != verticalSet.begin())
                left_line--;
            else
                left_line = verticalSet.end();

            int right;
            if(right_line == verticalSet.end())
                right = MAX;
            else
                right = *right_line;

            int left;
            if(left_line == verticalSet.end())
                left = -1;
            else
                left = *left_line;

            ans += X.size() - X.order_of_key(*X.upper_bound(left));
            ans -= X.order_of_key(*X.lower_bound(right));
        }
        else {
            if(not horizontalSet.size()){
                X.insert(x);
                Y.insert(y);
                continue;
            }

            auto right_line = horizontalSet.lower_bound(y);

            auto left_line = right_line;
            if(left_line != horizontalSet.begin())
                left_line--;
            else
                left_line = horizontalSet.end();

            int right;
            if(right_line == horizontalSet.end())
                right = MAX;
            else
                right = *right_line;

            int left;
            if(left_line == horizontalSet.end())
                left = -1;
            else
                left = *left_line;

            ans += Y.size() - Y.order_of_key(*Y.upper_bound(left));
            ans -= Y.order_of_key(*Y.lower_bound(right));
        }

        if(is_vertical_line[x])
            vertical_pos[is_vertical_line[x]].insert(y);
        if(is_horizontal_line[y])
            horizontal_pos[is_horizontal_line[y]].insert(x);

        X.insert(x);
        Y.insert(y);
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

