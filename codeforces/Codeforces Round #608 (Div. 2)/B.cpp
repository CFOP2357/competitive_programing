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

    int W = 0, B = 0;

    for(auto c : s)
        if(c == 'W')
            W++;
        else
            B++;

    if(W%2 and B%2){
        cout<<"-1\n";
        return;
    }

    vector<int> ans;
    if(W%2 == 0){
        for(int i = 1; i < n; i++){
            if(s[i] == 'W' and s[i-1] == 'W'){
                s[i] = s[i-1] = 'B';
                ans.push_back(i);
            }
            else if(s[i-1] == 'W'){
                s[i] = 'W';
                s[i-1] = 'B';
                ans.push_back(i);
            }
        }
    }
    else {
        for(int i = 1; i < n; i++){
            if(s[i] == 'B' and s[i-1] == 'B'){
                s[i] = s[i-1] = 'W';
                ans.push_back(i);
            }
            else if(s[i-1] == 'B'){
                s[i] = 'B';
                s[i-1] = 'W';
                ans.push_back(i);
            }
        }
    }

    assert(ans.size() <= 3*n);

    cout<<ans.size()<<"\n";
    for(auto i : ans)
        cout<<i<<" ";
    cout<<"\n";
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

