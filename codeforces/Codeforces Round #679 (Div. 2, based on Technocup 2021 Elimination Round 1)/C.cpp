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

#define MAX 100005
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

int selected[MAX];

void solve(){

    vector<pii> nxt;

    for(int i=0; i<6; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        b.push_back(z);
    }

    for(int i=0; i<6; i++)
        for(int j=0; j<n; j++){
            nxt.push_back({b[j]-a[i], j});
        }

    sort(all(nxt));

    int i = 0, j = 0;
    int sz = 0;
    ull ans = LLONG_MAX;

    for(j=0; j<nxt.size(); j++){
        if(!selected[nxt[j].second])
            sz++;
        selected[nxt[j].second]++;
        while(selected[nxt[i].second]>1)
            selected[nxt[i++].second]--;

        if(sz>=n){
            ans = min(nxt[j].first - nxt[i].first, ans);
        }
    }

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

