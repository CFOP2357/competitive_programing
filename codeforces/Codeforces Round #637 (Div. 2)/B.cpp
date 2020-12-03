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
ull n, k;

void solve(){
    a.clear();

    cin>>n>>k;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    vector<ull> sum(1, 0);
    for(int i=1; i<n-1; i++){
        sum.push_back(sum.back());
        if(a[i]>max(a[i-1], a[i+1]))
            sum.back()++;
    }
    sum.push_back(sum.back());

    ull t = 1;
    for(int i=0; i+k-1<sum.size(); i++){
        t = max(sum[i+k-2]-sum[i]+1, t);
    }

    ull l = 0;
    for(l =0; sum[l+k-2]-sum[l]+1 != t; l++);

    cout<<t<<" "<<l+1<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

