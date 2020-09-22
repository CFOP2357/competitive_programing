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

vector<ull> b;
ull m;

void solve(){
    b.clear();

    string s; cin>>s;
    cin>>m;
    for(int i=0; i<m; i++){
        ull z; cin>>z;
        b.push_back(z);
    }
    string ans(m, ' ');

    sort(all(s), greater<char>());
    int j = 0;

    for(int i=0; i<=1300; i++){
        for(int k =0; k<m; k++){
            if(b[k] == i)
                ans[k] = s[j++];
        }
    }

    cout<<ans<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

