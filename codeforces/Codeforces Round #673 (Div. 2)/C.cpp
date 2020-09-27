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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
int n;

void solve(){
    a.clear(); b.clear();
    cin>>n;
    map<int, int> d; //max distance between two elements of same value
    map<int, int> last; //last position of element
    set<int> element;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);

        if(element.find(z) == element.end())
            d[z] = i+1;

        element.insert(z);

        d[z] = max(d[z], i-last[z]);
        last[z] = i;
    }

    vector<int> ans(n+5, INT_MAX);

    for(int e : element){
        d[e] = max(d[e], n-last[e]);
    }

    for(auto p : d){ //mark min
        int value = p.first, dist = p.second;
        //cout<<value<<" "<<dist<<"\n";
        /*int pos = lower_bound(all(ans), value)-ans.begin() + 1;
        cout<<pos<<"\n";*/
        ans[dist] = min(ans[dist], value);
    }

    for(int i=1; i<=n; i++)
        ans[i] = min(ans[i-1], ans[i]);

    for(int i=1; i<=n; i++)
        if(ans[i]==INT_MAX) ans[i] = -1;

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<"\n";

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
5
1 2 3 4 5
*/
