#include <iostream>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

#define MAX 1000100
#define MOD 1000000007

typedef long long ull;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedSet;
typedef tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update> orderedMultiSet;

#define findBO find_by_order
#define findBK order_of_key
*/

vector<ull> a;
vector<ull> b;
ull n;
int times[300];

void solve(){
    a.clear(); b.clear();
    cin>>n;
    fill(times, times+300, 0);
    for(int i=0; i<n; i++){
        string s; cin>>s;
        for(char c : s)
            times[c]++;
    }
    for(int i=0; i<300; i++)
        if(times[i]%n){
            cout<<"NO\n";
            return;
        }
    cout<<"YES\n";
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

