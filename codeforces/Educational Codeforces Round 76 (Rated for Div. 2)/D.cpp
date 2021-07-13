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
vector<pii> p;
ll n, m;
string s;

void solve(){
    a.clear(); p.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ll z; cin>>z;
        a.push_back(z);
    }

    cin>>m;
    for(int i=0; i<m; i++){
        ll power, endurance; cin>>power>>endurance;
        p.push_back({power, endurance});
    }

    { //O(mlogm)
        sort(all(p)); //O(mlogm)
        vector<pii> new_p;

        for(auto heroe : p){ //O(m)
            while(new_p.size() and new_p.back().second <= heroe.second)
                new_p.pop_back();
            new_p.push_back(heroe);
        }

        p=new_p;
    }


    ll ans = 0;
    ll monster = 0;
    ll last_monster = -1;
    while(monster < n){ //O(nlogm) amortized
        if(last_monster == monster){
            cout<<"-1\n";
            return;
        }
        last_monster = monster;

        ll j = monster;
        ll s = 1;
        ll max_power = a[j];
        ll current_heroe = lower_bound(all(p), make_pair(max_power, s)) - p.begin();
        while(j<n and current_heroe < p.size() and s<=p[current_heroe].second){
            j++;
            s++;
            if(j<n){
                max_power = max(max_power, a[j]);
                current_heroe = lower_bound(all(p), make_pair(max_power, s)) - p.begin();
            }
        }

        ans++;
        monster = j;
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

