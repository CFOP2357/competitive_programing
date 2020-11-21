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
ull n,q;
string s;

void test(){
    int l, r;
    cin>>l>>r;
    string z = s.substr(l-1, r-l+1);

    if(z.size()<2){
        cout<<"NO\n";
        return;
    }

    for(int i=0; i<z.size()-1; i++){
        int k = 0;
        for(int j = 0; j<s.size(); j++){
            if(s[j]==z[k]){
                if(k++ == i)
                    j++;
            }
        }

        if(k==z.size()){
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";
}

void solve(){
    cin>>n>>q;
    cin>>s;


    while(q--){
        test();
    }

}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}

