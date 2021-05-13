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

#define MAX 5010
#define MOD 1000000007

ull dp[MAX][MAX];

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

ull product_rotation(int l, int r){ //[l, r]
    if(l>r)
        return 0;
    if(dp[l][r])
        return dp[l][r];
    if(l==r)
        return dp[l][r] = a[l]*b[l];
    if(l+1==r)
        return dp[l][r] = a[l]*b[r] + a[r]*b[l];
    return dp[l][r] = a[l]*b[r] + a[r]*b[l] + product_rotation(l+1, r-1);
}


void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        b.push_back(z);
    }

    ull total_product = 0;
    for(int i=0; i<n; i++)
        total_product += a[i]*b[i];
    ull left_product = 0;

    ull ans = total_product;

    for(int i=0; i<n; i++){
        ull right_product = total_product - left_product;

        for(int j=i; j<n; j++){
                right_product -= a[j]*b[j];
                ans = max(ans, left_product + product_rotation(i, j) + right_product);
        }

        left_product += a[i]*b[i];
    }
    cout<<ans<<"\n";
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

