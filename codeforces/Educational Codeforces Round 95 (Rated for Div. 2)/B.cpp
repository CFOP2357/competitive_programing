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

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

#define MAX 1000100
#define MOD 1000000007

vector<ull> a;
vector<ull> b;
vector<bool> l;
ull n;

void solve(){
    a.clear(); b.clear(); l.clear();
    cin>>n;

    for(int i=0;i<n; i++){
        int z; cin>>z;
        a.push_back(z);
    }

    for(int i=0;i<n; i++){
        bool z; cin>>z;
        l.push_back(z);
    }

    for(int i=0; i<n; i++){
        if(!l[i]){
            b.push_back(a[i]);
        }
    }

    sort(b.begin(), b.end());

    int s = 0;
    for(int i=0; i<n; i++){
        if(!l[i]){
            a[i] = b[s++];
        }
    }

    ull sum = 0;
    int k = 0;
    for(int i=n-1; i>=0; i--){
        sum+=a[i];
        if(sum >= 0 && !l[i]) k = i;

    }

    queue<int> last;
    stack<int> change;
    for(int i=k; i<n; i++){
        if(!l[i]){
            if(a[i]>=0){
                change.push(i);
            }
            else last.push(i);
        }
    }

    while(last.size() && change.size()){
        swap(a[last.front()], a[change.top()]);
        last.pop(); change.pop();
    }



    for(int k : a)
        cout<<k<<" ";
    cout<<"\n";

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

