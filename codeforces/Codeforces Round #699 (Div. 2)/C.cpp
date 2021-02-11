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

vector<ull> a;
vector<ull> b;
vector<ull> c;
ull n, m;

void solve(){
    a.clear(); b.clear(); c.clear();

    map<ull, vector<ull>> want;
    map<ull, ull> firstToWant;

    cin>>n>>m;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        b.push_back(z);

        if(a[i]!=b[i])
            want[z].push_back(i+1);
        firstToWant[z] = i+1;
    }
    for(int i=0; i<m; i++){
        ull z; cin>>z;
        c.push_back(z);
    }

    vector<ull> ans(m, 0);

    if(!firstToWant[c[m-1]]){
        cout<<"NO\n";
        return;
    }
    ans[m-1] = firstToWant[c[m-1]];

    for(int i = m-1; i>=0; i--){
        auto &v = want[c[i]];

        if(!v.size()){
            ans[i] = ans[m-1];
        }
        else {
            ans[i]=v.back();
            a[v.back()-1] = c[i];
            v.pop_back();
        }

    }

    for(int i = 0; i<n; i++)
        if(a[i]!=b[i]){
            cout<<"NO\n";
            return;
        }

    cout<<"YES\n";
    for(ull Ans : ans)
        cout<<Ans<<" ";
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

