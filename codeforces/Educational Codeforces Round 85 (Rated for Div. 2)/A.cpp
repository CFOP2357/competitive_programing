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

void solve(){
    a.clear(); b.clear();
    cin>>n;

    int last_p = 0, last_c = 0;
    bool possible = true;
    for(int i=0; i<n; i++){

        int p, c; cin>>p>>c;

        int d = p - last_p;

        if(p==last_p && c!=last_c)
            possible=false;
        if(p<last_p || c<last_c)
            possible=false;
        if(c-last_c>d)
            possible=false;
        if(c>p)
            possible=false;

        last_p = p;
        last_c = c;

    }

    if(possible)
        cout<<"YES\n";
    else
        cout<<"NO\n";


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

