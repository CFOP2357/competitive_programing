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

#define MAX 1000000100
#define MOD 1000000007

vector<pii> a;
ull n;

bool posible(ull cost){
    ull sum = 0;
    for(int i=0; i<a.size() && a[i].first>cost; i++){
        sum += a[i].second;
    }

    return sum<=cost;
}

ull bs(ull l, ull r){ //(l, r]
    if(l+1 >= r)
        return r;
    ull m = (l+r)/2;
    if(posible(m))
        return bs(l, m);
    return bs(m, r);
}

void solve(){
    cin>>n;

    a.assign(n, {0, 0});
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a[i].first = z;
    }
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a[i].second = z;
    }
    sort(all(a), greater<pii>());

    cout<<bs(0, MAX)<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

