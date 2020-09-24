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

#define MAX 300100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, q;

void solve(){
    a.clear(); b.clear();
    cin>>n>>q;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    b.push_back(a[0]);

    for(int i=1; i<n; i++){
        if(b.size()%2){ //el ultimo suma
            if(b.back() < a[i]){
                b.back() = a[i];
            }
            else{
                    b.push_back(a[i]);
            }
        }
        else { //el ultimo resta
            if(b.back() > a[i]){
                b.back() = a[i];
            }
            else {
                    b.push_back(a[i]);
            }
        }
    }

    if(b.size()%2 == 0)
        b.pop_back();

    ull ans = 0;
    ull m = 1;
    for(ull s : b){
        ans+= s*m;
        m*=-1;
    }

    cout<<ans<<"\n";

    while(q--){
        int l, r; cin>>l>>r;
        l--, r--;

        ull nl = a[r],  nr = a[l];

        auto change = [&](int i, ull to) {
            if(i>0) ans -= max((ull)0, a[i] - a[i-1]);
            else ans -= a[i];
            if(i<n-1) ans -= max(a[i+1] - a[i], (ull)0);

            a[i] = to;

            if(i>0) ans += max(to - a[i-1], (ull)0);
            else ans += a[i];
            if(i<n-1) ans += max(a[i+1] - to, (ull)0);
        };

        change(l, nl);
        change(r, nr);

        cout<<ans<<"\n";

    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

