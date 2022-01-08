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

vector<pii> a;
int n;

void solve(){
    a.clear();


    map<pii, bool> exist_range;

    cin>>n;
    for(int i = 0; i < n; i++){
        int l, r;
        cin>>l>>r;

        a.push_back({l, r});
        exist_range[{l, r}] = true;
    }

    sort(all(a));


    map<pii, int> ans;
    for(int i = 0; i < n; i++){
        if(a[i].first == a[i].second)
            ans[a[i]] = a[i].first;

        if(exist_range[{a[i].first, a[i].second+1}])
            ans[{a[i].first, a[i].second+1}] = a[i].second + 1;
        else if(exist_range[{a[i].first-1, a[i].second}])
            ans[{a[i].first-1, a[i].second}] = a[i].first-1;
        else
            for(int j = i+1; j < n; j++){
                if(a[i].second + 2 == a[j].first and exist_range[{a[i].first, a[j].second}])
                    ans[{a[i].first, a[j].second}] = a[i].second + 1;
            }
    }

    for(auto [range, d] : ans)
        cout<<range.first<<" "<<range.second<<" "<<d<<"\n";
    cout<<"\n";
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

