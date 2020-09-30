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

#define MAX 1001000
#define MOD 1000000007

vector<pii> r;
vector<pii> sl;
ull n, m;

int d[MAX];

void solve(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        ull a, b;
        cin>>a>>b;
        r.push_back({a, b});
    }

    for(int i=0; i<m; i++){
        ull a, b;
        cin>>a>>b;
        sl.push_back({a, b});
    }

    fill(d, d+MAX, -1); //cout<<"\n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(r[j].first>sl[i].first || r[j].second>sl[i].second) continue;

            int x = sl[i].first - r[j].first;
            int y = sl[i].second - r[j].second;

            //cout<<x<<" "<<y<<"\n";

            d[x] = max(d[x], y);
        } //cout<<"#\n";
    }

    int ans = INT_MAX;
    int y = 0;
    for(int i = MAX-1; i>=0; i--){
        y = max(y, d[i]+1);
        //cout<<i<<" "<<d[i]<<"\n";
        ans = min(ans, y+i);
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

