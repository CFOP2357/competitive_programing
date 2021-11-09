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

deque<ll> a;
deque<ll> b;
ll n, m;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i = 0; i < n; i++){
        ll t, d; cin>>t>>d;
        if(d == 1)
            b.push_back(t);
        else
            a.push_back(t);
    }

    sort(all(a));
    sort(all(b));

    ll current_time = 0;
    ll current_d = 0;
    while(a.size() or b.size()){
        if(current_d == 0 and a.size() and current_time >= a.front()){
            current_time = max(a.front()+10, current_time);
            a.pop_front();
        }
        else if(current_d == 1 and b.size() and current_time >= b.front()){
            current_time = max(b.front()+10, current_time);
            b.pop_front();
        }
        else if(b.empty() or (a.size() and a.front() < b.front())){
            ll d = max(current_time, a.front());

            current_time = d+10;
            a.pop_front();

            current_d = 0;
        }
        else {
            ll d = max(current_time, b.front());

            current_time = d+10;
            b.pop_front();

            current_d = 1;
        }
    }

    cout<<current_time<<"\n";
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

