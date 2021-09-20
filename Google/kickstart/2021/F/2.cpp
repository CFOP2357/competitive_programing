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

typedef long long ull;
typedef long long ll;
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, D, k;
string s;

struct Attraction{
    ll h;
    ll s;
    ll e;
};

void solve(){
    vector<Attraction> attractions;

    cin>>D>>n>>k;
    for(int i=0; i<n; i++){
        ll h, s, e; cin>>h>>s>>e;
        attractions.push_back({h, s, e});
    }


    ll ans = 0;
    for(int d = 1; d <= D; d++){
        priority_queue<ll, vector<ll>, greater<ll>> H;
        ll current_ans = 0;
        for(auto &attraction : attractions){
            if(attraction.s <= d and d <= attraction.e){
                current_ans += attraction.h;
                H.push(attraction.h);

                if(H.size() > k){
                    current_ans -= H.top();
                    H.pop();
                }
            }
        }

        ans = max(ans, current_ans);
    }

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


