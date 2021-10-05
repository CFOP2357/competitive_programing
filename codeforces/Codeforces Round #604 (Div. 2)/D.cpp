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

ll a, b, c, d;

void solve(){
    cin>>a>>b>>c>>d;

    deque<ll> ans1;
    deque<ll> ans2;
    deque<ll> ans3;

    while(a){
        ans1.push_back(0);
        a--;
        if(b){
            b--;
            ans1.push_back(1);
        }
    }

    while(d){
        ans3.push_front(3);
        d--;
        if(c){
            c--;
            ans3.push_front(2);
        }
    }

    ll r = min(b, c);
    while(r--){
        ans2.push_back(2);
        ans2.push_back(1);
        b--, c--;
    }

    if(b){
        ans1.push_front(1);
        b--;
    }
    if(c){
        ans3.push_back(2);
        c--;
    }

    if(a or b or c or d){
        cout<<"NO\n";
        return;
    }

    deque<ll> ans;
    for(auto k : ans1)
        ans.push_back(k);
    for(auto k : ans2)
        ans.push_back(k);
    for(auto k : ans3)
        ans.push_back(k);

    for(int i = 1; i < ans.size(); i++)
        if(abs(ans[i-1]-ans[i]) != 1){
            cout<<"NO\n";
            return;
        }

    cout<<"YES\n";
    for(auto k : ans)
        cout<<k<<" ";

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

