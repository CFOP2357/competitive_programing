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

ull k, l, r, t, x, y;

void solve(){
    cin>>k>>l>>r>>t>>x>>y;

    r-=l; k-=l;

    map<ull, bool> selected;

    if(y<=x){
        if(y+k <= r)
            k+=y;
        k-=x;
        t--;
        if(k>=0 && (x==y || t<=k/(x-y)))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    else {
        while(t>0){
            if(selected[k%x]){
                cout<<"Yes\n";
                return;
            }
            selected[k%x]=true;
            t -= k/x;
            k = k%x + y;

            if(k>r && t>0){
                cout<<"No\n";
                return;
            }
        }
        cout<<"Yes\n";
    }


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

