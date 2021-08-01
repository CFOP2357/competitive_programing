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

vector<set<int>> friends;
ll ans;
ll n, m;

bool is_vulnerable(int v){
    return (friends[v].size() && *friends[v].rbegin() > v);
}

void add(int u, int v){
    if(!is_vulnerable(u) and v>u)
        ans--;
    if(!is_vulnerable(v) and u>v)
        ans--;
    friends[u].insert(v);
    friends[v].insert(u);
}

void rem(int u, int v){
    if(is_vulnerable(u)){
        friends[u].erase(v);
        if(!is_vulnerable(u))
            ans++;
    }
    else{
        friends[u].erase(v);
    }

    if(is_vulnerable(v)){
        friends[v].erase(u);
        if(!is_vulnerable(v))
            ans++;
    }
    else{
        friends[v].erase(u);
    }
}

void solve(){
    cin>>n>>m;
    friends.assign(n+1, set<int>());
    ans = n;
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        add(u, v);
        //cout<<ans<<"#\n";
    }

    ll q; cin>>q;
    while(q--){
        int t; cin>>t;
        if(t==1){
            int u, v; cin>>u>>v;
            add(u, v);
        }
        else if(t==2){
            int u, v; cin>>u>>v;
            rem(u, v);
        }
        else
            cout<<ans<<"\n";
    }

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

