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
ull n;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    b.assign(n+1, 0);
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        b[z] = 0;
    }

    stack<pii> last; //value, pos
    for(int i=0; i<n; i++){
        while(last.size() && last.top().first>=a[i]){
            if(last.top().first>a[i]){
                b[last.top().first] = max(b[last.top().first], abs(last.top().first-i));
            }
            last.pop();
        }
        if(last.size())
            b[a[i]] = max(b[a[i]], abs(last.top().second-i));
        last.push({a[i], i});
    }

    for(auto &B : b)
        B = max(n-B, 0);

    vector<int> dead(n+1, INT_MAX);
    for(int i=1; i<=n; i++)
        dead[b[i]] = min(dead[b[i]], i);

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

