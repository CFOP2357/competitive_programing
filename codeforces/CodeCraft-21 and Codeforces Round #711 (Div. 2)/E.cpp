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

vector<ull> a;
vector<ull> b;
ull n, m;
string s;

void query(int a, int b){
    cout<<'?'<<" "<<a<<" "<<b<<endl;
    cout.flush();
    string ans; cin>>ans;
    if(ans == "Yes"){
        cout<<"!"<<" "<<a<<" "<<b<<endl;
        exit(0);
    }
}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }
    //sort(all(a), greater<pii>());

    priority_queue<pair<ull, pii>> nxt;
    map<pii, bool> selected;
    for(int i=0; i<n; i++){

        if(a[i] == n || a[i]==0)
            continue;

        for(int j=n-1; j>=0; j--){
            if(a[j] == n || a[j]==0)
                continue;
            if(i==j)
                continue;
            nxt.push({a[i] - a[j], {i+1, j+1}});
        }

    }

    while(nxt.size()){
        int u = nxt.top().second.first, v = nxt.top().second.second;
        nxt.pop();


        if(selected[{u, v}] || selected[{v, u}])
            continue;
        selected[{u, v}] = true;

        query(u, v);

    }

    cout<<"! 0 0"<<endl;

}


int main(){
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //srand (time(NULL));

    int t=1;
    while(t--){
        solve();
    }

    return 0;
}

