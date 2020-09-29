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

#define MAX 200100
#define MOD 1000000007

ull n;

ull seg[MAX];


void solve(){

    cin>>n;

    set<ull> last;
    ull s = 0;
    int ans = 0;
    last.insert(0);

    for(int i=0; i<n; i++){
        ull z; cin>>z;
        s+=z;
        if(last.find(s) != last.end()){
            ans++;
            last.clear();
            last.insert(0);
            s = z;
        }
        last.insert(s);
    }

    cout<<ans<<"\n";
}

/*
10
1 2 3 -3 -2 -1 4 5 -5 -4

11
1 2 3 -3 -2 -1 4 5 -5 -4 -1
*/

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

