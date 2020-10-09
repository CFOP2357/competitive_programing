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

void solve(){
    a.clear(); b.clear();
    cin>>n;
    a.push_back(0);
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    b.assign(n+5, 0);

    for(int i=1; i<=n; i++){
        b[i] = 1;
        for(int j=1; j*j <= i; j++){
            if(i%j == 0){
                if(a[i]>a[j])
                    b[i] = max(b[i], b[j]+1);
                if(a[i]>a[i/j])
                    b[i] = max(b[i], b[i/j]+1);
            }
        }
    }

    cout<<*max_element(all(b))<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

