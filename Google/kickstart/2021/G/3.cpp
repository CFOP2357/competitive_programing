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

typedef int ull;
typedef int ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
ull n, k;

void solve(){
    a.clear();

    cin>>n>>k;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    unordered_map<ll, ll> ans_for_K; ans_for_K[0] = 0;
    ll ans = INT_MAX;

    for(int i = n-1; i >= 0; i--){
        ll current_k = k;
        ll current_ans = 0;
        for(int j = i; j >= 0 and current_k >= 0; j--){
            current_ans += 1;
            current_k -= a[j];

            if(current_k >= 0)
            if(current_k == 0 or ans_for_K.find(current_k) != ans_for_K.end())
                ans = min(ans, current_ans + ans_for_K[current_k]);
        }

        current_k = 0;
        current_ans = 0;
        for(int j = i; j < n and current_k <= k; j++){
            current_k += a[j];
            current_ans += 1;

            if(ans_for_K.find(current_k) == ans_for_K.end())
                ans_for_K[current_k] = current_ans;
            ans_for_K[current_k] = min(ans_for_K[current_k], current_ans);
        }
    }

    if(ans > n)
        cout<<"-1\n";
    else
        cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    ull T = 1;
    int t=1; cin>>t;
    while(t--){
        cout<<"Case #"<<T<<": ";
        solve();
        T++;
    }

    return 0;
}


