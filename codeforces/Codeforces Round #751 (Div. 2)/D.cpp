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
typedef int ll;
typedef int ull;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;


#define MAX 1000100
#define MOD 1000000007

vector<ll> a{0};
vector<ll> b{0};
ll n, m;
string s;

void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        ll z; cin>>z;
        a.push_back(z);
    }
    for(int i = 1; i <= n; i++){
        ll z; cin>>z;
        b.push_back(z);
    }

    vector<ll> min_steps(n+1, INT_MAX);
    min_steps[n] = 0;

    map<ll, ll, greater<ll>> avaiable_jump;
    avaiable_jump[n] = 0;

    for(int d = n; d >= 0; d--){
        while(avaiable_jump.size() and avaiable_jump.begin()->first > d)
            avaiable_jump.erase(avaiable_jump.begin());

        if(avaiable_jump.empty())
            continue;

        min_steps[d] = avaiable_jump.begin()->second;

        int next_min_pos = (d + b[d]) - a[d + b[d]];
        int steps = min_steps[d]+1;

        if(next_min_pos < avaiable_jump.begin()->first){
            auto last_iterator = avaiable_jump.lower_bound(next_min_pos);
            if(last_iterator != avaiable_jump.end() and last_iterator->second <= steps)
                continue;

            avaiable_jump[next_min_pos] = steps;
            last_iterator = avaiable_jump.lower_bound(next_min_pos);

            last_iterator--;
            vector<int> to_erase;
            while(last_iterator != avaiable_jump.begin() and last_iterator->second >= steps){
                to_erase.push_back(last_iterator->first);
                last_iterator--;
            }
            if(avaiable_jump.begin()->second >= steps)
                to_erase.push_back(avaiable_jump.begin()->first);
            for(auto key : to_erase)
                avaiable_jump.erase(key);

        }
    }

    if(min_steps[0] == INT_MAX)
        cout<<"-1\n";
    else{
        cout<<min_steps[0]<<"\n";
        int steps = min_steps[0]-1;
        int last_pos = 0;

        vector<int> ans;
        ans.push_back(0);
        for(int d = 1; d <= n; d++){
            int next_min_pos = (d + b[d]) - a[d + b[d]];
            if(steps == min_steps[d] and next_min_pos <= last_pos){
                last_pos = d;
                steps--;
                ans.push_back(d);
            }
        }

        ans.pop_back();
        reverse(all(ans));
        for(int k : ans)
            cout<<k<<" ";
        cout<<"\n";
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

