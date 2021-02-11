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

ull a[MAX];
ull n;

int query(int i){

    if(i>n || i==0)
        return INT_MAX;
    if(a[i])
        return a[i];
    cout<<"? "<<i<<endl;
    cout.flush();
    cin>>a[i];
    return a[i];
}

int bS(int l, int r){
    if(l+1>=r){
        if(query(l-1) > query(l) && query(l+1) > query(l))
            return l;
        else
            return r;
    }

    ull m = (l+r)/2;

    if(query(m-1) > query(m) && query(m+1) > query(m))
            return m;

    if(query(m-1) < query(m+1))
        return bS(l, m);
    return bS(m, r);
}

void solve(){



    cin>>n;

    int k = bS(1, n);
    cout<<"! "<<k<<endl;
    cout.flush();
}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

