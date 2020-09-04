#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    ull a, b; cin>>a>>b;
    ull x, y; cin>>x>>y;
    ull n; cin>>n;
    ull ans = 0;

    ull minA = a - min(a-x, n);
    ull minB = b - min(b-y, n);

    if(minA < minB){
        swap(a, b);
        swap(x, y);
    }

    ull d = min(b-y, n);
    b -= d;
    n -= d;

    if(n){
        d = min(a-x, n);
        n -= d;
        a -= d;
    }

    cout<<a*b<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

