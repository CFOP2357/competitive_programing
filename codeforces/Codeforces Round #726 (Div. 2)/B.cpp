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
ull n, m, i, j;
string s;

ull dist(ull x1, ull y1, ull x2, ull y2){
    return abs(x1-x2)+abs(y1-y2);
}

void solve(){
    cin>>n>>m>>i>>j;

    ull d1 = min(dist(i, j, n, m), dist(i, j, 1, 1));
    ull d2 = min(dist(i, j, n, 1), dist(i, j, 1, m));

    if(d1>=d2)
        cout<<n<<" "<<m<<" "<<1<<" "<<1<<"\n";
    else
        cout<<n<<" "<<1<<" "<<1<<" "<<m<<"\n";
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

