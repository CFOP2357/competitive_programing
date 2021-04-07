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
ull n, s, k;

void solve(){
    a.clear();
    cin>>n>>s>>k;

    vector<bool> freeFloor(2010, true);
    for(int i=0; i<k; i++){
        ull z; cin>>z;
        a.push_back(z);

        if(abs(z-s)<=1000)
            freeFloor[z-s + 1000]=false;
    }

    ull ans = LLONG_MAX;
    for(int i=0; i<=2009; i++){
        if(i<1000 && 1000-i >= s)
            continue;
        if(i>1000 && i-1000 > n-s)
            continue;

        if(freeFloor[i])
            ans = min(ans, (ull)abs(i-1000));
    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

