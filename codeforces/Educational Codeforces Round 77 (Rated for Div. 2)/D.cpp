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

#include <time.h>

using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define all(a) a.begin(), a.end()

typedef long long ull;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m, k, t;
string s;

void solve(){
    cin>>m>>n>>k>>t;
    ull max_d = 0;
    for(int i=0; i<m; i++){
        ull z; cin>>z;
        a.push_back(z);
        max_d = max(max_d, z);
    } sort(all(a), greater<ull>());

    map<ull, vector<pii>> trap;
    while(k--){
        ull l, r, d; cin>>l>>r>>d;
        trap[d].push_back({r, l});
        max_d = max(max_d, d);
    }

    vector<ull> cost(max_d+2, n+1);
    set<pii> segments;
    ull current_cost = n+1;
    for(int d = max_d+1; d>=1; d--){
        for(auto segment : trap[d]){
            //cout<<segment.second<<" "<<segment.first<<"\t";
            ull r = segment.first, l=segment.second;
            auto it = segments.lower_bound({l, 0});
            while(it!=segments.end() and it->second <= r){
                current_cost -= (it->first - it->second +1)*2;
                r = max(r, it->first);
                l = min(l, it->second);
                segments.erase(it);
                it = segments.lower_bound({l, 0});
            }
            //cout<<l<<" "<<r<<"\n";
            current_cost += (r-l+1)*2;
            segments.insert({r, l});
        }
        cost[d-1] = current_cost;
    }

    /*for(auto c : cost)
        cout<<c<<" ";
    cout<<"\n";*/

    ull ans = 0;
    while(ans<m and cost[a[ans]]<=t)
        ans++;
    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

