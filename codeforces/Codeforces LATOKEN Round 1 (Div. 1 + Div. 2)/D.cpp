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

map<ull, vector<ull>> D;

void query1(ull r){
    cout<<"? "<<r<<endl;
    for(int v = 1; v<=n; v++){
        ull d; cin>>d;
        if(v>1)
            D[d%2].push_back(v);
        if(d==1){
            ull a = v, b = r;
            if(a>b)
                swap(a, b);
            ans.insert({a, b});
        }
    }
}

void query(ull r){
    cout<<"? "<<r<<endl;
    for(int v = 1; v<=n; v++){
        ull d; cin>>d;
        if(d==1){
            ull a = v, b = r;
            if(a>b)
                swap(a, b);
            ans.insert({a, b});
        }
    }
}

void solve(){

    cin>>n;

    query1(1);
    if(D[0].size()<D[1].size()){
        for(int v : D[0])
            query(v);
    }
    else{
        for(int v : D[1])
            query(v);
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

