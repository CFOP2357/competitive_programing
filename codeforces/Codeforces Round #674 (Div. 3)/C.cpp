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

//

int f(int i){
    int ans = i + n/(1+i);
    if(n%(n+i)) ans++;
    return ans;
}

int ts(int l, int r){
    if(l+1>=r)
        return l;
    int m1 = (r-l)/3 + l;
    int m2 = r - (r-l)/3;

    if(f(m1)<f(l) && f(m2)<f(r))
        return ts(m1, m2);
    if(f(m1)>f(l) && f(m2)<f(r))
        return ts(m1, m2);

}

void solve(){
    a.clear(); b.clear();
    cin>>n;

    int last = INT_MAX;

    for(int i=0; i<n; i++){
        int ans = i -1 + n/(1+i);
        if(n%(1+i)) ans++;

        if(ans>last) break;
        last = ans;
        //cout<<i<<" " <<n/(1+i) <<"\n";
        //cout<<ans<<"\n";
    }
    cout<<last<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

