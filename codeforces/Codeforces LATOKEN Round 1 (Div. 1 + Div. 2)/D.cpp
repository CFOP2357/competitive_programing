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

set<pii> ans;
stack<ull> nxt;
map<ull, bool> selected;
ull n;

void query(ull r){
    cout<<"? "<<r<<endl;
    map<ull, vector<ull>> D;
    for(int v = 1; v<=n; v++){
        ull d; cin>>d;
        D[d].push_back(v);
    }

    bool to_find = true;
    for(int d = 1; d<=n; d++){ //O(n) <- amortized
        if(D[d-1].size()>1 and D[d+1].size()){
            for(auto v : D[d])
                nxt.push(v);
        }
        if(D[d-1].size()==1){
            int u = D[d-1][0];
            for(auto v : D[d]){
                ull a = u, b = v;
                if(a>b)
                    swap(a, b);
                ans.insert({a, b});
            }
        }
    }
}

void solve(){

    cin>>n;

    ull v = rand()%n+1;
    nxt.push(v);
    while(ans.size()<n-1 && nxt.size()){ //O(n^2)
        ull r = nxt.top();
        nxt.pop();
        if(selected[r])
            continue;
        selected[r] = true;
        query(r);
    }

    cout<<"!"<<endl;
    for(auto edge : ans)
        cout<<edge.first<<" "<<edge.second<<endl;

}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

