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

map<pii, int> q;

int query(int l, int r){
    if(q.find({l, r})!=q.end())
        return q[{l, r}];

    cout<<"? "<<l<<" "<<r<<"\n";
    int ans; cin>>ans;
    cout.flush();
    q[{l, r}] = ans;
    return ans;
}

int bs(int l, int r, int x){
    if(r == l){
        return l;
    }
    else if(l+1==r){
        if(query(l, r) == l)
            return r;
        return l;
    }

    int m = (l+r)/2;

    if(x>=m){
        if(query(m, max(r, x))!=x)
            return bs(l, m, x);
        return bs(m, r, query(m, max(r, x)));
    }
    else {
        if(query(min(l, x), m)!=x)
            return bs(m, r, x);
        return bs(l, m, query(min(l, x), r));
    }
}

void solve(){

    cin>>n;

    ull ans = bs(1, n, query(1, n));
    cout<<"! "<<ans<<"\n";

}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

