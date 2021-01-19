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

bool ok(){
    vector<ull> b;
   for(int i=0; i<n; i++){
        b.push_back(a[i]);
   }

   for(int i=1; i<n; i++){
    b[i] -= b[i-1];
    if(b[i]<0)
        return false;
   }
   if(b.back())
        return false;
   return true;
}

void solve(){
    a.clear(); b.clear();
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    if(ok()){
        cout<<"YES\n";
        return;
    }

    vector<int> op;

    b.clear();
    for(int i=0; i<n; i++){
        b.push_back(a[i]);
   }

   for(int i=1; i<n; i++){
    b[i] -= b[i-1];
    if(b[i]<0){
        op.push_back(i);
        op.push_back(i+1);
        op.push_back(i-1);
        break;
    }
   }
   if(b.back())
        op.push_back(n-1);

    b.clear();
    for(int i=0; i<n; i++){
        b.push_back(a[i]);
   }

   for(int i=n-2; i>0; i--){
    b[i] -= b[i+1];
    if(b[i]<0){
        op.push_back(i+1);
        op.push_back(i-1);
        op.push_back(i);
        break;
    }
   }
   if(b[0])
        op.push_back(1);

    for(int p : op){

        if(p>0){
            swap(a[p], a[p-1]);
            if(ok()){
                cout<<"YES\n";
                return;
            }
            swap(a[p], a[p-1]);
        }
        if(p<n-1){
            swap(a[p], a[p+1]);
            if(ok()){
                cout<<"YES\n";
                return;
            }
            swap(a[p], a[p+1]);
        }
    }

    cout<<"NO\n";

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

