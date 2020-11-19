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
ull n, w;

void solve(){
    a.clear();

    cin>>n>>w;
    ull half = w + w%2;
    half /= 2;
    ull sum = 0;

    for(ull i=0; i<n; i++){
        ull z; cin>>z;
        if(z>w)
            continue;
        a.push_back({z, i});
        sum += z;

        if(z >= half){
            cout<<"1\n";
            cout<<i+1<<"\n";
            while(++i<n)
                cin>>z;
            return;
        }
    }

    //cout<<sum<<" "<<half<<"\n";

    if(sum<half){
        cout<<"-1\n";
        return;
    }

    sort(all(a));

    set<ull> ans;
    while(a.size() && sum > w){
        if(sum - a.back().first >= half)
            sum -= a.back().first;
        else
            ans.insert(a.back().second+1);
        a.pop_back();
    }

    for(auto a : ::a){
        ans.insert(a.second+1);
    }

    if(sum<half){
        cout<<"-1\n";
        return;
    }

    cout<<ans.size()<<"\n";
    for(auto e : ans)
        cout<<e<<" ";
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

