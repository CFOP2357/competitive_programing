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

vector<ull> l;
ull n, m;

void solve(){
    l.clear();
    cin>>n>>m;
    ull sum = 0, times_n = 0;
    for(int i=0; i<m; i++){
        ull z; cin>>z;
        l.push_back(z);
        sum+=z;

        if(z==n)
            times_n++;

    }

    if(times_n>1 || sum<n){
        cout<<"-1\n";
        return;
    }

    vector<ull> ans;
    ull i = 1, j=0;
    for(ull seg : l){
        if(sum>n){
            if(j+seg>n){
                cout<<"-1\n";
                return;
            }
            int d = min(sum-n, i-j-1);
            i -= d;
            sum -= d;
        }
        ans.push_back(i);
        j=i;
        i+=seg;
    }

    for(ull r : ans)
        cout<<r<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

