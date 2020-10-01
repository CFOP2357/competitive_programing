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

ull n, m;

void solve(){

    cin>>n>>m;

    vector<bool> row(n, false);
    vector<bool> column(m, false);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            bool a; cin>>a;
            row[i] = a || row[i];
            column[j] = a || column[j];
        }
    }

    int r = n, c = m;
    for(bool k : row)
        r -= k;
    for(bool k : column)
        c -= k;

    int sz = min(r, c);
    if(sz%2)
        cout<<"Ashish\n";
    else cout<<"Vivek\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

