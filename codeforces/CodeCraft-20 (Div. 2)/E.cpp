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

#define MAX 100100
#define MOD 1000000007

ull dp[MAX][130];

vector<pii> a;
vector<ull> b;
ull n, p, k;

vector<vector<ull>> s;

int sz(ull selected){
    int ans = 0;
    ull pot = 1;
    for(ull pot=1; pot<=selected; pot*=2)
        ans += (bool)(selected&pot);
    return ans;
}

void solve(){
    a.clear(); b.clear();
    cin>>n>>p>>k;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back({z, i});
    }

    sort(all(a), greater<pii>());

    for(int i=0; i<n; i++){
        fill(dp[i], dp[i]+130, -1);
        s.push_back(vector<ull>());
        for(int j=0; j<p; j++){
            ull z; cin>>z;
            s.back().push_back(z);
        }
    }

    dp[0][0] = 0;
    for(int i=0; i<n; i++){
        for(int selected=0; selected<=(1<<p)-1; selected++){

            //cout<<dp[i][selected]<<" ";

            if(dp[i][selected]<0)
                continue;

            dp[i+1][selected] = max(dp[i+1][selected], dp[i][selected]);
            if((i-sz(selected)) < k)
                dp[i+1][selected] = max(dp[i+1][selected], dp[i][selected]+a[i].first);

            ull pot = 1;
            for(int j=0; j<p; j++, pot*=2){
                if(! (selected&pot) ){
                    dp[i+1][selected|pot] = max(dp[i+1][selected|pot], dp[i][selected]+s[a[i].second][j]);
                }
            }
        } //cout<<"\n";

    }

    /*for(int selected=0; selected<=(1<<p)-1; selected++)
        cout<<dp[n][selected]<<" ";
    cout<<"\n\n";*/

    cout<<dp[n][(1<<p)-1]<<"\n";


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

