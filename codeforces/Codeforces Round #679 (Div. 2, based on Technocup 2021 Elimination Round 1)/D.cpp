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

#define MAX 100100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
ull n;

int pos[MAX];

void solve(){
    a.clear(); b.clear();
    cin>>n;
    set<int, greater<int>> space;
    for(int i=0; i<2*n; i++){
        ull z=0; char c; cin>>c;
        if(c=='+')
            a.push_back(1);
        else a.push_back(0);
        if(c=='-'){
            cin>>z;
            pos[z] = i;
        }
        else {
            space.insert(i);
        }

        b.push_back(z);
    }

    for(int i=1; i<=n; i++){
        auto d = space.lower_bound(pos[i]);
        if(d==space.end()){
            cout<<"NO\n";
            return;
        }

        b[*d] = i;

        space.erase(d);
    }

    priority_queue<int, vector<int>, greater<int>> actual;
    vector<int> ans;

    for(int i=0; i<2*n; i++){
        if(a[i]){
            actual.push(b[i]);
            ans.push_back(b[i]);
        }
        else {
            if(!actual.size() || actual.top()!=b[i]){
                cout<<"NO\n";
                return;
            }
            actual.pop();
        }
    }

    cout<<"YES\n";
    for(int res : ans)
        cout<<res<<" ";
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

