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

vector<pii> a;
ull n;

ull calc(ull d, int X, int Y){
    ull ans = 0;

    ans += abs(a[0].first-X) + abs(a[0].second-Y);

    ull x = X, y = Y - d;
    ans += abs(a[1].first-x) + abs(a[1].second-y);

    x = X - d, y = Y - d;
    ans += abs(a[2].first-x) + abs(a[2].second-y);

    x = X - d, y = Y;
    ans += abs(a[3].first-x) + abs(a[3].second-y);

    return ans;
}

ull calc1(ull d, int X, int Y){
    ull ans = 0;

    ans += abs(a[1].first-X) + abs(a[1].second-Y);

    ull x = X, y = Y + d;
    ans += abs(a[0].first-x) + abs(a[0].second-y);

    x = X + d, y = Y + d;
    ans += abs(a[3].first-x) + abs(a[3].second-y);

    x = X + d, y = Y;
    ans += abs(a[2].first-x) + abs(a[2].second-y);

    return ans;
}

ull calc2(ull d, int X, int Y){
    ull ans = 0;

    ans += abs(a[2].first-X) + abs(a[2].second-Y);

    ull x = X - d, y = Y + d;
    ans += abs(a[0].first-x) + abs(a[0].second-y);

    x = X - d, y = Y;
    ans += abs(a[1].first-x) + abs(a[1].second-y);

    x = X, y = Y + d;
    ans += abs(a[3].first-x) + abs(a[3].second-y);

    return ans;
}

ull calc3(ull d, int X, int Y){
    ull ans = 0;

    ans += abs(a[3].first-X) + abs(a[3].second-Y);

    ull x = X - d, y = Y;
    ans += abs(a[0].first-x) + abs(a[0].second-y);

    x = X - d, y = Y - d;
    ans += abs(a[1].first-x) + abs(a[1].second-y);

    x = X, y = Y - d;
    ans += abs(a[2].first-x) + abs(a[2].second-y);

    return ans;
}

void solve(){
    a.clear();
    for(int i=0; i<4; i++){
        ull x, y; cin>>x>>y;
        a.push_back({x, y});
    }
    sort(all(a));

    ull ans = LLONG_MAX;

    do{
        map<ull, bool> selected;
        for(int j=0;j<=1; j++){
            for(int k=2;k<=3; k++){
                ull d = abs(a[j].first-a[k].first);
                if(selected[d])
                    continue;
                selected[d] = true;
                for(int l = 0; l<4; l++){
                    for(int m = 0; m<4; m++){
                        ans = min(calc(d, a[l].first, a[m].second), ans);
                        /*ans = min(calc1(d, a[l].first, a[m].second), ans);
                        ans = min(calc2(d, a[l].first, a[m].second), ans);
                        ans = min(calc3(d, a[l].first, a[m].second), ans);*/
                    }
                }//
            }
        }

        for(int j=1;j<=2; j++){
            for(int k=0;k<=3; k+=3){
                ull d = abs(a[j].second-a[k].second);
                if(selected[d])
                    continue;
                selected[d] = true;
                for(int l = 0; l<4; l++){
                    for(int m = 0; m<4; m++){
                        ans = min(calc(d, a[l].first, a[m].second), ans);
                        /*ans = min(calc1(d, a[l].first, a[m].second), ans);
                        ans = min(calc2(d, a[l].first, a[m].second), ans);
                        ans = min(calc3(d, a[l].first, a[m].second), ans);*/
                    }
                }
            }
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

