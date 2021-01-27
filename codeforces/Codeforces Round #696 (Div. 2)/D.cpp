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

bool ok(const vector<ull> &a){
    vector<ull> b;
   for(int i=0; i<a.size(); i++){
        b.push_back(a[i]);
        if(b.back()<0)
            return false;
   }

   for(int i=1; i<a.size(); i++){
    b[i] -= b[i-1];
    if(b[i]<0)
        return false;
   }
   if(b.back())
        return false;
   return true;
}

void solve(){
    a.clear();
    a.push_back(0);
    cin>>n;
    for(int i=0; i<n; i++){
        ull z; cin>>z;
        a.push_back(z);
    }

    if(ok(a)){
        cout<<"YES\n";
        return;
    }

    vector<ull> prefix(a), sufix(a);
    prefix.push_back(0); sufix.push_back(0);

    for(int i=1; i<=n+1; i++)
        prefix[i] = max((prefix[i-1]==-1)?-1:prefix[i]-prefix[i-1], (ull)-1);
    for(int i=n; i>=0; i--)
        sufix[i] = max((sufix[i+1]==-1)?-1:sufix[i]-sufix[i+1], (ull)-1);

    for(int i=2; i<=n; i++){
        vector<ull> try_= {prefix[i-2], a[i], a[i-1], sufix[i+1]};
        if(ok(try_)){
            cout<<"YES\n";
            return;
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

