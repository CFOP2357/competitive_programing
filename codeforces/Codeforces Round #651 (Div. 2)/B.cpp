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

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

void solve(){
    a.clear(); b.clear();
    cin>>n;

    stack<int> odd, even;
    for(int i=1; i<=2*n; i++){

        ull z; cin>>z;
        a.push_back(z);

        if(z%2)
            odd.push(i);
        else even.push(i);

    }

    n--;
    while(n--){
        if(even.size() >= odd.size()){
            cout<<even.top()<<" "; even.pop();
            cout<<even.top()<<"\n"; even.pop();
        }
        else {
            cout<<odd.top()<<" "; odd.pop();
            cout<<odd.top()<<"\n"; odd.pop();
        }
    }


}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

