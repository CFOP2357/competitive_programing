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
ull n, A, B;

void solve(){
    a.clear(); b.clear();
    cin>>A>>B>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        b.push_back(z);
    }

    vector<pii> nxt;
    for(int i=0; i<n; i++)
    {
        if(b[i]%A)
            b[i]+=A;
        ull d = (b[i]/A)*(a[i]);
        nxt.push_back({a[i], i});
    }
    sort(all(nxt));

    for(int j=0; j<n; j++){

        int i = nxt[j].second;

        if(B<=0){
            cout<<"NO\n";
            return;
        }


        B -= ((b[i]/A)-1)*(a[i]);

        if(B<=0){
            cout<<"NO\n";
            return;
        }

        B -= a[i];
    }

    cout<<"YES\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

