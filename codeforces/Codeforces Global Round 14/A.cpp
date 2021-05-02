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
typedef pair<ull, ull> pii;
typedef vector<ull> vi;

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n, m, x;
string s;

void solve(){
    a.clear(); ull sum = 0;
    cin>>n>>x;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
        sum += z;
    }

    if(sum==x){
        cout<<"NO\n";
        return;
    }

    sort(all(a), greater<ull>());
    ull current_sum = 0;
    for(int i=0; i<n; i++){
        current_sum += a[i];
        if(current_sum == x){
            current_sum -= a[i];
            swap(a[i], a.back());
            current_sum += a[i];
        }
    }

    cout<<"YES\n";
    for(ull k : a)
        cout<<k<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

