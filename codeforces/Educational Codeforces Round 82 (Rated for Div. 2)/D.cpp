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

multiset<ull, greater<ull>> a;
vector<ull> b;
ull n, m;

void solve(){
    a.clear(); b.clear();
    cin>>n>>m;
    ull sum = 0;
    for(int i=0; i<m; i++){
        ull z; cin>>z;
        sum += z;
        a.insert(z);
    }

    if(sum<n){
        cout<<"-1\n";
        return;
    }

    ull ans = 0;

    while(a.size()){
        ull k = *a.begin();
        a.erase(a.begin());

        ull lastK = k;
        if(k<=n){
            n-=k;
            sum -= k;
        }
        else if(sum-k < n){
            while(k>n){
                k/=2;
                ans++;
            }
            n-=k;
            sum -= lastK;
            if(sum<n){
                sum += k;
                a.insert(k);
            }
        }
        else sum -= lastK;

        if(!n)
            break;

    }

    cout<<ans<<"\n";




}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

/*
1
182 6
1 1 1 2 2 256
*/
