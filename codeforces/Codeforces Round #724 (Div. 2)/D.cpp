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
ull n, m;
string s;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    set<int> r;
    set<int, greater<int>> l;
    ull m;
    cin>>m;
    r.insert(m); l.insert(m);
    bool ans = true;
    for(int i=1; i<n; i++){
        ull b; cin>>b;
        if(b!=m){

            if(b>m){
                if(r.upper_bound(m) != r.end() and b > *r.upper_bound(m)){
                    ans = false;
                }
            }
            else{
                if(l.upper_bound(m) != l.end() and b < *l.upper_bound(m)){
                    ans = false;
                }
            }

        }
        m=b;
        r.insert(b);
        l.insert(b);
    }

    if(ans)
        cout<<"YES\n";
    else
        cout<<"NO\n";

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

