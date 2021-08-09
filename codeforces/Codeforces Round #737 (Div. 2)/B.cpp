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
ll n, m, k;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n>>k;

    priority_queue<pii, vector<pii>, greater<pii>> nxt; //val, pos
    for(int i=0; i<n; i++){
        ll z; cin>>z;
        nxt.push({z, i});
    }

    ll last_pos = nxt.top().second;
    ll segments = 1;
    nxt.pop();

    while(nxt.size()){
        if(nxt.top().second != last_pos+1)
            segments++;
        last_pos = nxt.top().second;
        nxt.pop();
    }

    if(segments <= k)
        cout<<"Yes\n";
    else
        cout<<"No\n";

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

/*
2
10 5
6 1 10 4 5 9 8 7 3 2
10 3
5 7 10 1 4 3 8 2 6 9
*/
