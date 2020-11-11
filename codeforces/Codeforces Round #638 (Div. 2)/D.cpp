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
ull n;

void solve(){
    cin>>n;
    vector<ull> ans;
    stack<ull> p;

    ull s = 1;
    p.push(1);

    while(s<n){
        if(s+2*p.top()<=n){
            ans.push_back(p.top());
            s += 2*p.top();
            p.push(p.top()*2);
        }
        else if(s+p.top() == n){
            ans.push_back(0);
            s += p.top();
            p.push(p.top());
        }
        else if(s+p.top() < n){
            n-=s; n-=p.top();
            ans.push_back(n);
            s += p.top() + n;
            p.push(p.top());
        }
        else {
            ans.pop_back();
            s -= p.top();
            p.pop();
            s += p.top();
            ans.push_back(0);
            p.push(p.top());
        }
    }

    cout<<ans.size()<<"\n";
    for(ull r : ans)
        cout<<r<<" ";
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

/*

*/
