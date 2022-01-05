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
    a.clear(); b.clear();
    cin>>n;
    cin>>s;

    vector<deque<int>> ans;

    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            int l = i;

            int r = n-1;
            while(r > 0 and s[r] == '1')
                r--;

            if(r > l){
                ans.push_back(deque<int>());

                deque<int> L;
                deque<int> R;

                while(l < r){
                    if(s[l] == '1' and s[r] == '0'){
                        L.push_back(l+1);
                        R.push_front(r+1);

                        swap(s[l], s[r]);
                    }
                    else if(s[l] == '0')
                        l++;
                    else
                        r--;
                }

                for(auto i : L)
                    ans.back().push_back(i);
                for(auto i : R)
                    ans.back().push_back(i);
            }
        }
    }

    cout<<ans.size()<<"\n";
    for(auto &subsequence : ans){
        cout<<subsequence.size()<<" ";
        for(auto i : subsequence)
            cout<<i<<" ";
        cout<<"\n";
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

