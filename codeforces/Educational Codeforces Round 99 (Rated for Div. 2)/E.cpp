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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<pii> a;
ull n;

ll calc(int d, int X, int Y){
    ll ans = 0;

    ans += (ll)abs(a[0].first-X) + (ll)abs(a[0].second-Y);

    int x = X, y = Y - d;
    ans += (ll)abs(a[1].first-x) + (ll)abs(a[1].second-y);

    x = X - d, y = Y - d;
    ans += (ll)abs(a[2].first-x) + (ll)abs(a[2].second-y);

    x = X - d, y = Y;
    ans += (ll)abs(a[3].first-x) + (ll)abs(a[3].second-y);

    return ans;
}

ll calc1(int d, int X, int Y){
    ll ans = 0;

    ans += (ll)abs(a[1].first-X) + (ll)abs(a[1].second-Y);

    int x = X, y = Y + d;
    ans += (ll)abs(a[0].first-x) + (ll)abs(a[0].second-y);

    x = X + d, y = Y + d;
    ans += (ll)abs(a[3].first-x) + (ll)abs(a[3].second-y);

    x = X + d, y = Y;
    ans += (ll)abs(a[2].first-x) + (ll)abs(a[2].second-y);

    return ans;
}

ll calc2(int d, int X, int Y){
    ll ans = 0;

    ans += (ll)abs(a[2].first-X) + (ll)abs(a[2].second-Y);

    int x = X - d, y = Y + d;
    ans += (ll)abs(a[0].first-x) + (ll)abs(a[0].second-y);

    x = X - d, y = Y;
    ans += (ll)abs(a[1].first-x) + (ll)abs(a[1].second-y);

    x = X, y = Y + d;
    ans += (ll)abs(a[3].first-x) + (ll)abs(a[3].second-y);

    return ans;
}

ll calc3(int d, int X, int Y){
    ll ans = 0;

    ans += (ll)abs(a[3].first-X) + (ll)abs(a[3].second-Y);

    int x = X - d, y = Y;
    ans += abs(a[0].first-x) + (ll)abs(a[0].second-y);

    x = X - d, y = Y - d;
    ans += (ll)abs(a[1].first-x) + (ll)abs(a[1].second-y);

    x = X, y = Y - d;
    ans += (ll)abs(a[2].first-x) + (ll)abs(a[2].second-y);

    return ans;
}

void solve(){
    a.clear();
    for(int i=0; i<4; i++){
        ull x, y; cin>>x>>y;
        a.push_back({x, y});
    }
    sort(all(a));

    ll ans = LLONG_MAX;
    unordered_set<int> D;

    for(int j=0;j<4; j++)
        for(int k=0;k<4; k++)
            D.insert(abs(a[j].first-a[k].first)), D.insert(abs(a[j].second-a[k].second));


    do{

        for(auto d : D){
                for(int l = 0; l<4; l++){
                    for(int m = 0; m<4; m++){
                        ans = min(calc(d, a[l].first, a[m].second), ans);
                        ans = min(calc1(d, a[l].first, a[m].second), ans);
                        //ans = min(calc2(d, a[l].first, a[m].second), ans);
                        //ans = min(calc3(d, a[l].first, a[m].second), ans);
                    }
                }//
        }

    }while(next_permutation(all(a)));

    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
