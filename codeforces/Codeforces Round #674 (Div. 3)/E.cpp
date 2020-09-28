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

vector<ull> a;
vector<ull> b;
ull n;

int ans1 = 0, ans2 = 0;

void solve(){


    int a1, a2, a3; cin>>a1>>a2>>a3;
    int b1, b2, b3; cin>>b1>>b2>>b3;

    int sum = a1-b2 + a2-b3 + a3-b1;
    if(sum) ans2++;

    sum = b1-a2 + b2-a3 + b3-a1;
    if(sum<=0) ans1++;

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    cout<<ans1<<" "<<ans2<<"\n";

    return 0;
}

