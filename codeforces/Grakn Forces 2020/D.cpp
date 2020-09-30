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

vector<pii> r;
vector<pii> sl;
ull n, m;

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

    ull x=0, y=0;
    for(int i=0; i<n; i++){
        //int ny = r[i].first, nx = r[j].second;
        for(int j=0; j<m; j++){
            if(sl[j].first >= r[i].first)
                y = max(y, sl[j].first-r[i].first+1);
            if(sl[j].second >= r[i].second)
                x = max(x, sl[j].second-r[i].second+1);
        }
    }

    cout<<min(x,y)<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

