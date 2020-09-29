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

ull n;

int a1, a2, a3;
int b1, b2, b3;

void solve(){

    int n; cin>>n;

    cin>>a1>>a2>>a3;
    cin>>b1>>b2>>b3;

    {

        vector<pair<int, int>> order;
        order.push_back({0, 0});
        order.push_back({0, 2});
        order.push_back({1, 0});
        order.push_back({1, 1});
        order.push_back({2, 1});
        order.push_back({2, 2});

        sort(all(order));

        int ans = min(a1, b2) + min(a2, b3) + min(a3, b1);

        do {

            int a[3] = {a1, a2, a3};
            int b[3] = {b1, b2, b3};

            for(auto p : order){
                auto &a1 = a[p.first];
                auto &b3 = b[p.second];
                int d = min(a1, b3);
                a1 -= d; b3 -= d;
            }

            ans = min(a[0] + a[1] + a[2], ans);

        }while(next_permutation(all(order)));

        cout<<ans<<" ";
    }

    cout<< min(a1, b2) + min(a2, b3) + min(a3, b1)<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

