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

vector<ll> fib;
vector<int> ans;

ll n;

map<ll, bool> selected;
void find_ans(){
    if(selected[n])
        return;
    selected[n] = true;

    if(n == 1){
        string s = "";
        for(int k : ans){
            s += (string(k, 'A') + "B");
        }
        cout<<s<<"\n";
        exit(0);
    }

    for(int i = 73; i >= 1; i--){
        if(n%fib[i] == 0){
            n /= fib[i];
            ans.push_back(i);
            find_ans();
            ans.pop_back();
            n *= fib[i];
        }
    }
}

/// AAAAAAAAAB

void solve(){
    cin>>n;

    fib.push_back(1);
    fib.push_back(2);
    for(int i = 2; i < 74; i++)
        fib.push_back(fib[i-1] + fib[i-2]);

    find_ans();

    cout<<"IMPOSSIBLE\n";
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

